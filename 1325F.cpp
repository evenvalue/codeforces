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

void print(const vector<int> &ans, const int type) {
  cout << type << '\n';
  if (type == 2) cout << ans.size() << '\n';
  for (const int x : ans) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
  exit(0);
}

inline void solution() {
  const int n = read<int>();
  const int m = read<int>();

  int k = 0;
  while (k * k < n) {
    k++;
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> parent(n, -1);
  vector<int> depth(n, -1);
  function<void(int)> dfs = [&](const int x) {
    for (const int y : g[x]) {
      if (depth[y] != -1) continue;
      depth[y] = depth[x] + 1;
      parent[y] = x;
      dfs(y);
    }
  };

  dfs(0);

  set<pair<int, int>> s;
  for (int x = 0; x < n; x++) {
    for (const int y : g[x]) {
      if (y == parent[x]) continue;
      if (depth[x] - depth[y] >= k - 1) {
        vector<int> cycle;
        for (int cur = x; cur != y; cur = parent[cur]) {
          cycle.push_back(cur);
        }
        cycle.push_back(y);
        print(cycle, 2);
      }
    }
    s.insert(make_pair(depth[x], x));
  }

  vector<int> independent;
  while (not s.empty()) {
    const auto [d, x] = *s.rbegin();
    s.erase(prev(s.end()));
    for (const int y : g[x]) {
      auto it = s.find({depth[y], y});
      if (it != s.end()) s.erase(it);
    }
    independent.push_back(x);
  }

  while (independent.size() > k) independent.pop_back();

  print(independent, 1);
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