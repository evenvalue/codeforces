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
  int x, y, w;
};

inline void solution(vector<int> &ans) {
  const int n = read<int>();
  const int m = read<int>();
  const int k = read<int>();
  const int q = read<int>();

  vector<bool> visit(n + m);
  vector<int> p(n + m);

  auto check = [&](const vector<vector<pair<int, int>>> &g) {
    fill(visit.begin(), visit.end(), false);

    bool possible = true;
    function<void(int)> dfs = [&](const int x) {
      visit[x] = true;
      for (const auto [y, w] : g[x]) {
        if (visit[y]) {
          possible &= ((p[x] ^ p[y] ^ w) == 0);
        } else {
          p[y] = p[x] ^ w;
          dfs(y);
        }
      }
    };

    for (int x = 0; x < n + m; x++) {
      if (visit[x]) continue;
      dfs(x);
    }

    return possible;
  };

  vector<vector<pair<int, int>>> g(n + m);
  dsu d(n + m);

  for (int i = 0; i < k; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1 + n;
    const int w = read<int>();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
    d.unite(x, y);
  }

  vector<edge> edges(q);
  for (auto &[x, y, w] : edges) {
    x = read<int>() - 1;
    y = read<int>() - 1 + n;
    w = read<int>();
  }

  auto get_graph = [&](const int queries) {
    auto adj = g;
    for (int i = 0; i < queries; i++) {
      const auto &[x, y, w] = edges[i];
      adj[x].emplace_back(y, w);
      adj[y].emplace_back(x, w);
    }
    return adj;
  };

  int lo = -1, hi = q;
  while (lo < hi) {
    const int mid = (lo + hi + 1) / 2;
    if (check(get_graph(mid))) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  if (lo == -1) {
    cout << 0 << '\n';
  } else {
    cout << ans[d.comp - 1] << '\n';
  }

  for (int i = 0; i < q; i++) {
    const auto [x, y, w] = edges[i];
    d.unite(x, y);
    cout << (i < lo ? ans[d.comp - 1] : 0) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  vector<int> ans(kMaxN);
  ans[0] = 1;
  for (int i = 1; i < kMaxN; i++) {
    ans[i] = (ans[i - 1] * (1LL << 30)) % kMod;
  }

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution(ans);
  }
}