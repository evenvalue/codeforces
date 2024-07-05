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
  int x, y;
  int64 w;

  bool operator<(const edge &other) const {
    return w < other.w;
  }
};

inline void solution() {
  const int n = read<int>();
  const int m = read<int>();
  const int k = read<int>();
  const int q = read<int>();

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    const int w = read<int>();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  vector<int64> dist(n, kInf64);
  vector<int> root(n);

  auto dijkstra = [&]() {
    min_heap<pair<int64, int>> q;
    for (int i = 0; i < k; i++) {
      q.emplace(0, i);
      dist[i] = 0;
      root[i] = i;
    }
    while (not q.empty()) {
      const auto [d, x] = q.top();
      q.pop();
      if (d != dist[x]) continue;
      for (const auto [y, w] : g[x]) {
        if (dist[y] > dist[x] + w) {
          dist[y] = dist[x] + w;
          root[y] = root[x];
          q.emplace(dist[y], y);
        }
      }
    }
  };

  dijkstra();

  vector<edge> edges;
  for (int x = 0; x < n; x++) {
    for (const auto [y, w] : g[x]) {
      if (y < x) continue;
      edges.push_back({root[x], root[y], dist[x] + w + dist[y]});
    }
  }

  vector<set<int>> tokens(k);
  for (int i = 0; i < q; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    tokens[x].insert(i);
    tokens[y].insert(i);
  }

  sort(edges.begin(), edges.end());

  vector<int64> ans(q);

  dsu d(k);
  for (auto [x, y, w] : edges) {
    if (d.same(x, y)) continue;
    x = d.find(x);
    y = d.find(y);

    if (tokens[x].size() < tokens[y].size()) swap(tokens[x], tokens[y]);
    for (const int token : tokens[y]) {
      if (tokens[x].contains(token)) {
        tokens[x].erase(token);
        ans[token] = w;
      } else {
        tokens[x].insert(token);
      }
    }
    tokens[y].clear();

    d.unite(x, y);
    if (d.find(x) != x) swap(tokens[x], tokens[y]);
  }

  for (const int64 x : ans) {
    cout << x << '\n';
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