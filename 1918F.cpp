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

inline void solution() {
  const int n = read<int>();
  const int k = read<int>() + 1;

  vector<vector<int>> g(n);
  for (int x = 1; x < n; x++) {
    const int p = read<int>() - 1;
    g[p].push_back(x);
  }

  vector<int> depth(n);
  vector<int> max_depth(n);

  function<void(int, int)> dfs1 = [&](const int x, const int d) {
    depth[x] = max_depth[x] = d;
    for (const int y : g[x]) {
      dfs1(y, d + 1);
      max_depth[x] = max(max_depth[x], max_depth[y]);
    }
  };

  dfs1(0, 0);
  for (int x = 0; x < n; x++) {
    sort(g[x].begin(), g[x].end(), [&](const int a, const int b) {
      return max_depth[a] < max_depth[b];
    });
  }

  max_heap<int> time_skip;
  function<int(int)> dfs2 = [&](const int x) {
    for (int i = 0; i < (int) g[x].size() - 1; i++) {
      const int y = g[x][i];
      time_skip.push(dfs2(y) - depth[x]);
    }
    return (g[x].empty() ? 0 : dfs2(g[x].back())) + 1;
  };

  time_skip.push(dfs2(0) - 1);

  int time = 2 * (n - 1);
  for (int i = 0; i < k and not time_skip.empty(); i++) {
    if (time_skip.top() < 0) break;
    time -= time_skip.top();
    time_skip.pop();
  }

  cout << time << '\n';
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