#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef LOCAL
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
T read() {
  T x;
  cin >> x;
  return x;
}

template<typename T1, typename T2>
pair<T1, T2> read_pair() {
  pair<T1, T2> p;
  cin >> p.first;
  cin >> p.second;
  return p;
}

template<typename T>
vector<T> read_vec(const int n, const int index = 0) {
  vector<T> v(n + index);
  for (int i = index; i < n + index; i++) {
    v[i] = read<T>();
  }
  return v;
}

template<typename T>
vector<vector<T>> read_vec_vec(const int n, const int m, const int index_n = 0, const int index_m = 0) {
  vector<vector<T>> grid(n + index_n);
  for (int i = index_n; i < n + index_n; i++) {
    grid[i] = read_vec<T>(m, index_m);
  }
  return grid;
}

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e18 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

//so in this problem, I have two definitions.
//R(i) = b[i] + pref[i];
//L(i) = b[i] - pref[i - 1];

//for every query of the third type, I need to choose i1, i2, i3, i4 such that
//l <= i1 <= i2 < i3 <= i4 <= r, and
//L(i1) + R(i2) + L(i3) + R(i4) is maximum.

//This can be done using lazy segtree with each node holding a matrix of size 5x5.
//Here the matrix[i][j] represents parts [i, j] of the answer has been calculated
//in that node. This is going to be fun to implement. Let us do that now!

template<class Node>
class LazySegTree {
  using Unite_t = std::function<Node(const Node &, const Node &)>;
  using Apply_t = std::function<void(Node &, const Node &)>;
  using Unlazy = std::function<void(Node &)>;

  size_t n = 0;
  std::vector<Node> t;

  Unite_t unite;
  Apply_t apply;
  Unlazy activate;

  void push(const size_t x, const size_t l, const size_t r) {
    const size_t mid = (l + r) / 2;
    const size_t y = 2 * (mid - l + 1) + x;
    apply(t[x + 1], t[x]);
    apply(t[y], t[x]);
    activate(t[x]);
  }

  void update(const size_t x, const size_t l, const size_t r, const size_t ql, const size_t qr, const Node upd) {
    if (ql <= l and r <= qr) {
      apply(t[x], upd);
      return;
    }
    push(x, l, r);
    const size_t mid = (l + r) / 2;
    const size_t y = 2 * (mid - l + 1) + x;
    if (ql <= mid) {
      update(x + 1, l, mid, ql, qr, upd);
    }
    if (mid < qr) {
      update(y, mid + 1, r, ql, qr, upd);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  Node query(const size_t x, const size_t l, const size_t r, const size_t ql, const size_t qr) {
    if (ql <= l and r <= qr) {
      return t[x];
    }
    push(x, l, r);
    const size_t mid = (l + r) / 2;
    const size_t y = 2 * (mid - l + 1) + x;
    if (qr <= mid) {
      return query(x + 1, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(y, mid + 1, r, ql, qr);
    } else {
      return unite(query(x + 1, l, mid, ql, qr), query(y, mid + 1, r, ql, qr));
    }
  }

  void build(const int x, const int l, const int r, const std::vector<Node> &a) {
    if (l == r) {
      t[x] = a[l];
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    build(x + 1, l, mid, a);
    build(y, mid + 1, r, a);
    t[x] = unite(t[x + 1], t[y]);
  }

public:
  LazySegTree(const size_t n, const Node e, const Unite_t unite, const Apply_t apply, const Unlazy activate)
      : n(n), t(2 * n - 1, e), unite(unite), apply(apply), activate(activate) {}

  LazySegTree(const std::vector<Node> &a, const Unite_t unite, const Apply_t apply, const Unlazy activate)
      : n(a.size()), t(2 * n - 1), unite(unite), apply(apply), activate(activate) {
    build(0, 0, n - 1, a);
  }

  void update(const int ql, const int qr, const Node upd) {
    assert(0 <= ql and ql <= qr and qr < n);
    update(0, 0, n - 1, ql, qr, upd);
  }

  Node query(const int ql, const int qr) {
    assert(0 <= ql and ql <= qr and qr < n);
    return query(0, 0, n - 1, ql, qr);
  }

  LazySegTree<Node> &operator=(LazySegTree<Node> other) {
    swap(n, other.n);
    swap(t, other.t);
    swap(unite, other.unite);
    swap(apply, other.apply);
    swap(activate, other.activate);
    return *this;
  }
};

constexpr int N = 5;

struct node {
  array<array<int, N>, N> cost;
  int lazy_l = 0;
  int lazy_r = 0;

  node() = default;
  node(const int x, const int l, const int r) : lazy_l(l), lazy_r(r) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cost[i][j] = x;
      }
    }
  }
};

auto init_segtree(const vector<node> &a) {
  auto unite = [](const node &l, const node &r) {
    node ans(-kInf64, 0, 0);
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        for (int k = j; k < N; k++) {
          ans.cost[i][k] = max(ans.cost[i][k], l.cost[i][j] + r.cost[j][k]);
        }
      }
    }
    return ans;
  };

  auto apply = [](node &x, const node &upd) {
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        if ((i <= 0 and 1 <= j) or (i <= 2 and 3 <= j)) {
          x.cost[i][j] += upd.lazy_l;
        }
        if ((i <= 1 and 2 <= j) or (i <= 3 and 4 <= j)) {
          x.cost[i][j] += upd.lazy_r;
        }
      }
    }
    x.lazy_l += upd.lazy_l;
    x.lazy_r += upd.lazy_r;
  };

  auto activate = [](node &x) {
    x.lazy_l = x.lazy_r = 0;
  };

  return LazySegTree<node>(a, unite, apply, activate);
}

inline void solution() {
  const int n = read<int>();
  auto a = read_vec<int>(n, 1);
  auto b = read_vec<int>(n, 1);

  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  auto L = [&](const int i) {
    return b[i] - pref[i - 1];
  };

  auto R = [&](const int i) {
    return b[i] + pref[i];
  };

  vector<node> leaves(n + 2, node(-kInf64, 0, 0));
  for (int i = 1; i <= n; i++) {
    auto &cur = leaves[i];
    for (int j = 0; j < N; j++) {
      cur.cost[j][j] = 0;
    }

    cur.cost[0][1] = L(i);
    cur.cost[0][2] = L(i) + R(i);
    cur.cost[1][2] = R(i);

    cur.cost[2][3] = L(i);
    cur.cost[2][4] = L(i) + R(i);
    cur.cost[3][4] = R(i);
  }

  auto st = init_segtree(leaves);

  int q = read<int>();
  while (q--) {
    const int t = read<int>();
    if (t == 1) {
      const int i = read<int>();
      const int x = read<int>();
      st.update(i + 1, n + 1, node(0, a[i] - x, 0));
      st.update(i, n, node(0, 0, x - a[i]));
      a[i] = x;
    } else if (t == 2) {
      const int i = read<int>();
      const int x = read<int>();
      st.update(i, i, node(0, x - b[i], x - b[i]));
      b[i] = x;
    } else {
      const int l = read<int>();
      const int r = read<int>();
      cout << st.query(l, r).cost[0][N - 1] << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}