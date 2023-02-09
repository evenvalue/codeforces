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

class dsu {
  int n;
  std::vector<int> e;

  int pfind(const int x) {
    return (e[x] < 0 ? x : e[x] = pfind(e[x]));
  }

public:
  dsu() : n(0), comp(0) {}
  explicit dsu(const int n) : n(n), comp(n), e(n, -1) {}

  int comp;

  int find(const int x) {
    assert(0 <= x and x < n);
    return pfind(x);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    comp--;
    return true;
  }

  void force_unite(int p, int x) {
    e[p] += e[x];
    e[x] = p;
  }

  bool same(const int x, const int y) {
    return (find(x) == find(y));
  }

  int size(const int x) {
    return -e[find(x)];
  }

  std::vector<std::vector<int>> components() {
    std::vector<std::vector<int>> res(n);
    for (int x = 0; x < n; x++) {
      res[pfind(x)].push_back(x);
    }
    res.erase(
        std::remove_if(res.begin(), res.end(), [&](const std::vector<int> &v) { return v.empty(); }),
        res.end());
    return res;
  }
};

struct edge {
  int x = -1;
  int y = -1;
  bool deleted = false;
};

struct query {
  int t;
  int x;
};

struct range {
  int l;
  int r;
};

struct node {
  int max = 0;
  int idx = -1;
};

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  const int q = read::Int();

  const vector<int> p = read::Vec<int>(n);

  vector<edge> edges(m);
  for (edge &e : edges) {
    e.x = read::Int() - 1;
    e.y = read::Int() - 1;
  }

  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    queries[i].t = read::Int();
    queries[i].x = read::Int() - 1;
    if (queries[i].t == 2) {
      edges[queries[i].x].deleted = true;
    }
  }

  for (int i = 0; i < m; i++) {
    const auto [x, y, del] = edges[i];
    if (del) continue;
    queries.push_back({2, i});
  }

  dsu d(n + m);

  vector<vector<int>> tree(n);
  vector<int> id(q);

  auto add_node = [&]() {
    const int new_node = (int) tree.size();
    tree.emplace_back();
    return new_node;
  };

  for (int i = (int) queries.size() - 1; i >= 0; i--) {
    if (queries[i].t == 1) {
      queries[i].x = d.find(queries[i].x);
      id[i] = queries[i].x;
    } else {
      auto [x, y, _] = edges[queries[i].x];

      if (d.same(x, y)) continue;

      x = d.find(x);
      y = d.find(y);
      const int z = add_node();

      d.force_unite(z, x);
      d.force_unite(z, y);
      tree[z].push_back(x);
      tree[z].push_back(y);
    }
  }

  const int root = tree.size() - 1;
  vector<range> ranges(root + 1);

  function<int(int, int)> dfs = [&](const int x, int time) -> int {
    ranges[x].l = time;
    for (const int y : tree[x]) {
      time = dfs(y, time) + 1;
    }
    return (ranges[x].r = time);
  };

  vector<int> leaders;
  for (int x = 0; x < n; x++) {
    leaders.push_back(d.find(x));
  }

  sort(leaders.begin(), leaders.end());
  leaders.erase(unique(leaders.begin(), leaders.end()), leaders.end());

  for (int i = 0, time = 0; i < leaders.size(); i++) {
    time = dfs(leaders[i], time) + 1;
  }

  SegTree<node> st(root + 1, node(), [&](const node &l, const node &r) {
    node ans;
    ans.max = max(l.max, r.max);
    ans.idx = (ans.max == l.max ? l.idx : r.idx);
    return ans;
  });

  for (int x = 0; x < n; x++) {
    assert(ranges[x].l == ranges[x].r);
    st.set(ranges[x].l, {p[x], ranges[x].l});
  }

  for (int i = 0; i < q; i++) {
    if (queries[i].t == 2) continue;
    const int x = id[i];
    const node ans = st.get(ranges[x].l, ranges[x].r);
    st.set(ans.idx, {0, ans.idx});
    cout << ans.max << '\n';
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