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
  const int m = read<int>();

  auto s = read<string>();

  vector f(m, vector<int>(m));
  for (int i = 1; i < n; i++) {
    const int x = s[i - 1] - 'a';
    const int y = s[i] - 'a';
    f[x][y]++, f[y][x]++;
  }

  const int kMaxMask = (1 << m);
  vector<int> dp(kMaxMask, kInf);

  dp[0] = 0;
  for (int mask = 1; mask < kMaxMask; mask++) {
    const int bits = __builtin_popcount(mask);
    for (int last = 0; last < m; last++) {
      if ((mask & (1 << last)) == 0) continue;
      int cost = 0;
      for (int i = 0; i < m; i++) {
        if (i == last) continue;
        cost += ((mask & (1 << i)) ? f[i][last] : -f[i][last]) * bits;
      }
      dp[mask] = min(dp[mask], dp[mask - (1 << last)] + cost);
    }
  }

  cout << dp[kMaxMask - 1] << '\n';
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