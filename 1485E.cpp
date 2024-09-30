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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read<int>();

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    const int x = read<int>() - 1;
    g[x].push_back(i);
    g[i].push_back(x);
  }

  auto a = read_vec<int>(n - 1, 1);

  vector<int> parent(n, -1);
  vector<int> index(n);

  vector<int> mn(n), mx(n);

  vector<int> dp(n);
  vector<int> ans(n);

  auto bfs = [&](const int s) {
    vector<int> level = {s};
    vector<int> next_level;

    while (not level.empty()) {
      next_level.clear();

      sort(level.begin(), level.end(), [&](const int x, const int y) {
        return a[x] < a[y];
      });

      for (const int x : level) {
        ans[x] = max(dp[x] + a[x] - a[level[0]], dp[x] + a[level.back()] - a[x]);
        for (const int y : g[x]) {
          if (y == parent[x]) continue;
          parent[y] = x;
          next_level.push_back(y);
        }
      }

      for (int i = 0; i < level.size(); i++) {
        const int x = level[i];
        index[x] = i;
        mn[i] = dp[x] - a[x];
        mx[i] = dp[x] + a[x];
      }

      for (int i = 1; i < level.size(); i++) {
        mn[i] = max(mn[i - 1], mn[i]);
      }

      for (int i = level.size() - 2; i >= 0; i--) {
        mx[i] = max(mx[i + 1], mx[i]);
      }

      for (const int y : next_level) {
        const int x = parent[y];
        dp[y] = dp[x] + max(a[x] - a[level[0]], a[level.back()] - a[x]);
        dp[y] = max({dp[y], a[x] + mn[index[x]], mx[index[x]] - a[x]});
      }

      swap(level, next_level);
    }
  };

  bfs(0);

  cout << *max_element(ans.begin(), ans.end()) << '\n';
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