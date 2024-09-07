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
  const int l = read<int>();
  auto a = read_vec<int>(n, 1);
  auto b = read_vec<int>(n, 1);

  vector<vector<int>> cost(n + 2, vector<int>(4));
  for (int i = 1; i <= n; i++) {
    cost[i][0] = a[i] + b[i];
    cost[i][1] = a[i] - b[i];
    cost[i][2] = -a[i] + b[i];
    cost[i][3] = -a[i] - b[i];
  }

  vector dp(n + 1, vector<int>(l + 1, -kInf64));

  dp[0][0] = 0;

  auto opp = [&](const int mask) {
    if (mask == 0 or mask == 3) return 3 - mask;
    return mask;
  };

  vector<vector<int>> diag_cost(n + 5, vector<int>(4, -kInf64));
  diag_cost[0] = cost[1];

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= min(i, l); k++) {
      dp[i][k] = dp[i - 1][k];
      for (int mask = 0; mask < 4; mask++) {
        dp[i][k] = max(dp[i][k], diag_cost[i - k][opp(mask)] + cost[i][mask]);
      }
      for (int mask = 0; mask < 4; mask++) {
        diag_cost[i - k][mask] = max(diag_cost[i - k][mask], dp[i][k] + cost[i + 1][mask]);
      }
    }
  }

  int ans = 0;
  for (int i = l; i <= n; i++) {
    ans = max(ans, dp[i][l]);
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