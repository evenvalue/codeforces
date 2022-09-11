#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

namespace read {
int Int() {
  int x;
  cin >> x;
  return x;
}
int64 Int64() {
  int64 x;
  cin >> x;
  return x;
}
char Char() {
  char c;
  cin >> c;
  return c;
}
string String() {
  string s;
  cin >> s;
  return s;
}
double Double() {
  return stod(String());
}
ld LongDouble() {
  return stold(String());
}
template<typename T1, typename T2>
pair<T1, T2> Pair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> Vec(const int n) {
  vector<T> v(n);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> VecVec(const int n, const int m) {
  vector<vector<T>> v(n);
  for (vector<T> &vec : v) {
    vec = Vec<T>(m);
  }
  return v;
}
}//namespace read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;

template<class node, class F = std::function<node(const node &, const node &)>>
class SegTree {
  int n = 0;
  std::vector<node> t;
  F unite;

  void build(const int x, const int l, const int r, const std::vector<node> &a) {
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

  void update(const int x, const int l, const int r, const int p, const node &v) {
    if (l == p and p == r) {
      t[x] = v;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (p <= mid) {
      update(x + 1, l, mid, p, v);
    } else {
      update(y, mid + 1, r, p, v);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  node query(const int x, const int l, const int r, const int ql, const int qr) const {
    if (ql <= l and r <= qr) {
      return t[x];
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (qr <= mid) {
      return query(x + 1, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(y, mid + 1, r, ql, qr);
    } else {
      return unite(query(x + 1, l, mid, ql, qr), query(y, mid + 1, r, ql, qr));
    }
  }

  void debug_node(const int x, const vector<int> &path) const {
    for (int i = 0; i < path.size(); i++) {
      cerr << path[i] << (i == path.size() - 1 ? ": " : " -> ");
    }
    cerr << t[x] << '\n';
  }

  void print_tree(const int x, const int l, const int r, vector<int> path) const {
    path.push_back(x);
    if (l == r) {
      debug_node(x, path);
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    print_tree(x + 1, l, mid, path);
    print_tree(y, mid + 1, r, path);
    debug_node(x, path);
  }

public:
  SegTree() = default;
  explicit SegTree(const int n, const node e, F f) : n(n), t(2 * n - 1, e), unite(std::move(f)) {}
  explicit SegTree(const std::vector<node> &a, F f) : n(a.size()), t(2 * (a.size()) - 1), unite(std::move(f)) {
    build(0, 0, n - 1, a);
  }

  void set(const int p, const node &v) {
    assert(0 <= p and p < n);
    update(0, 0, n - 1, p, v);
  }

  [[nodiscard]] node get(const int l, const int r) const {
    assert(0 <= l and l <= r and r < n);
    return query(0, 0, n - 1, l, r);
  }

  void print_tree() const {
    print_tree(0, 0, n - 1, {});
    cerr << "----------\n\n";
  }
};

struct range {
  int l1 = kInf, r1 = -kInf;
  int l2 = kInf, r2 = -kInf;

  range &operator+=(const range &other) {
    l1 = min(l1, other.l1);
    l2 = min(l2, other.l2);
    r1 = max(r1, other.r1);
    r2 = max(r2, other.r2);
    return *this;
  }
};

bool valid(const int l, const int r) {
  return (l != kInf and r != -kInf);
}

inline void solution() {
  const int n = read::Int(), q = read::Int();
  vector<int> cost = read::Vec<int>(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> depth(n);
  int odds = 0, evens = 0;
  vector<range> ranges(n);

  function<range(int, int, int)> dfs = [&](const int x, const int p, const int d) {
    if (d) {
      ranges[x].l1 = odds;
      ranges[x].r1 = odds;
      odds++;
    } else {
      ranges[x].l2 = evens;
      ranges[x].r2 = evens;
      evens++;
    }
    depth[x] = d;
    for (const int y : g[x]) {
      if (y == p) continue;
      ranges[x] += dfs(y, x, 1 - d);
    }
    return ranges[x];
  };

  dfs(0, 0, 0);

  SegTree<int64> odd(odds + 1, 0, [&](const int64 l, const int64 r) {
    return l + r;
  });
  SegTree<int64> even(evens + 1, 0, [&](const int64 l, const int64 r) {
    return l + r;
  });

  for (int query = 0; query < q; query++) {
    const int type = read::Int(), x = read::Int() - 1;
    const auto &cur = ranges[x];
    if (type == 1) {
      const int v = read::Int() * (depth[x] ? 1 : -1);
      if (valid(cur.l1, cur.r1)) {
        odd.set(cur.l1, odd.get(cur.l1, cur.l1) + v);
        odd.set(cur.r1 + 1, odd.get(cur.r1 + 1, cur.r1 + 1) - v);
      }
      if (valid(cur.l2, cur.r2)) {
        even.set(cur.l2, even.get(cur.l2, cur.l2) - v);
        even.set(cur.r2 + 1, even.get(cur.r2 + 1, cur.r2 + 1) + v);
      }
    } else {
      if (depth[x]) {
        cout << odd.get(0, cur.l1) + cost[x] << '\n';
      } else {
        cout << even.get(0, cur.l2) + cost[x] << '\n';
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}