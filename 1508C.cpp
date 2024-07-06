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
  int x;
  int y;
  int w;

  bool operator<(const edge &other) const {
    return w < other.w;
  }
};

inline void solution() {
  const int n = read<int>();
  const int m = read<int>();

  vector<edge> edges(m);
  vector<set<int>> g(n);
  int last_edge = 0;

  for (auto &[x, y, w] : edges) {
    x = read<int>() - 1;
    y = read<int>() - 1;
    w = read<int>();
    g[x].insert(y);
    g[y].insert(x);
    last_edge ^= w;
  }

  set<int> unvisited;
  for (int i = 0; i < n; i++) unvisited.insert(i);

  dsu d(n);
  function<void(int)> dfs = [&](const int x) {
    unvisited.erase(x);
    auto it = unvisited.begin();
    for (int y = -1; (it = unvisited.upper_bound(y)) != unvisited.end();) {
      y = *it;
      if (not g[x].contains(y)) {
        d.unite(x, y);
        dfs(y);
      }
    }
  };

  for (int x = 0; x < n; x++) {
    if (unvisited.contains(x)) dfs(x);
  }

  if (m + n - d.comp != n * 1LL * (n - 1) / 2) last_edge = 0;

  sort(edges.begin(), edges.end());

  int64 ans = 0;

  dsu d2(n);
  for (const auto [x, y, w] : edges) {
    if (d2.same(x, y)) continue;
    if (d.same(x, y)) {
      last_edge = min(last_edge, w);
    } else {
      ans += w;
    }
    d.unite(x, y);
    d2.unite(x, y);
  }

  cout << ans + last_edge << '\n';
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