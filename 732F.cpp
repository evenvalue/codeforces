#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
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
constexpr int kMaxN = 2e5 + 10;

class two_connected {
  const int n;
  const vector<vector<pair<int, int>>> g;

  vector<int> tin;
  vector<int> low;

  vector<int> parent;

  int time = 0;
  void dfs1(const int x, const int p, const int edge) {
    tin[x] = low[x] = time++;
    for (const auto &[y, i] : g[x]) {
      if (y == p and edge == i) continue;
      if (tin[y] != -1) {
        low[x] = min(low[x], tin[y]);
      } else {
        dfs1(y, x, i);
        low[x] = min(low[x], low[y]);
        if (low[y] <= tin[x]) {
          parent[y] = x;
        }
      }
    }
  }

  void dfs2(const int x) {
    if (comp[x] != -1) return;
    if (parent[x] == -1) {
      comp[x] = x;
      return;
    }
    dfs2(parent[x]);
    comp[x] = comp[parent[x]];
  }

public:
  vector<int> comp;

  explicit two_connected(const vector<vector<pair<int, int>>> &g) : n(g.size()), g(g) {
    tin.assign(n, -1);
    low.assign(n, -1);
    parent.assign(n, -1);
    comp.assign(n, -1);

    for (int x = 0; x < n; x++) {
      if (tin[x] == -1) dfs1(x, -1, -1);
    }

    for (int x = 0; x < n; x++) {
      if (comp[x] == -1) dfs2(x);
    }
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
};

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();

  dsu d(n);
  vector<edge> edges(m);
  vector<vector<pair<int, int>>> g(n);

  for (int i = 0; i < m; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);

    edges[i].x = x;
    edges[i].y = y;

    d.unite(x, y);
  }

  two_connected tc(g);
  vector<bool> visit(n);

  function<void(int, int)> direct_same = [&](const int x, const int p) {
    visit[x] = true;
    for (const auto [y, i] : g[x]) {
      if (y == p) continue;
      if (tc.comp[y] != tc.comp[x]) continue;

      if (visit[y]) {
        edges[i].x = y;
        edges[i].y = x;
      } else {
        edges[i].x = x;
        edges[i].y = y;
        direct_same(y, x);
      }
    }
  };

  for (int x = 0; x < n; x++) {
    if (not visit[x]) {
      direct_same(x, -1);
    }
  }

  vector<vector<int>> group(n);
  for (int x = 0; x < n; x++) {
    group[tc.comp[x]].push_back(x);
  }

  fill(visit.begin(), visit.end(), false);

  function<void(int)> direct_diff = [&](const int x) {
    visit[x] = true;

    for (const auto [y, i] : g[x]) {
      if (visit[y]) continue;
      if (tc.comp[x] != tc.comp[y]) {
        edges[i].x = y;
        edges[i].y = x;
      }
      direct_diff(y);
    }
  };

  auto solve_component = [&](const vector<int> &comp) {
    int mx = -1, sz = 0;
    for (const int x : comp) {
      if (group[x].size() > sz) {
        mx = x;
        sz = group[x].size();
      }
    }

    direct_diff(mx);

    return sz;
  };

  int ans = kInf;

  vector<vector<int>> comp = d.components();
  for (const vector<int> &c : comp) {
    ans = min(ans, solve_component(c));
  }

  cout << ans << '\n';
  for (const auto [x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << '\n';
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