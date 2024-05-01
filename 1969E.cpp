#include <bits/stdc++.h>
using namespace std;

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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

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

auto init_segtree(const int n) {
  struct node {
    int val = 0;
    int lazy = 0;
  };

  auto unite = [](const node &l, const node &r) {
    node ans;
    ans.val = min(l.val, r.val);
    return ans;
  };

  auto apply = [](node &x, const node &upd) {
    x.val += upd.lazy;
    x.lazy += upd.lazy;
  };

  auto activate = [](node &x) {
    x.lazy = 0;
  };

  return LazySegTree<node>(n, node(), unite, apply, activate);
}

inline void solution() {
  const int n = read<int>();

  auto a = read_vec<int>(n);
  for (int &x : a) x--;

  vector<int> last(n, -1);
  vector<int> second_last(n, -1);

  auto st = init_segtree(n);

  int ans = 0;
  for (int i = 0, l = 0; i < n; i++) {
    st.update(last[a[i]] + 1, i, {.lazy = 1});
    if (last[a[i]] != -1) {
      st.update(second_last[a[i]] + 1, last[a[i]], {.lazy = -1});
    }
    second_last[a[i]] = last[a[i]];
    last[a[i]] = i;
    const int foo = st.query(l, i).val;
    if (foo == 0) {
      ans++;
      l = i + 1;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}