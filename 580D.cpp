#include <bits/stdc++.h>
using namespace std;

#define int long long

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

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  const int k = read::Int();

  const vector<int> a = read::Vec<int>(n);

  vector<vector<int>> bonus(n, vector<int>(n + 1));
  for (int i = 0; i < k; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    const int c = read::Int();
    bonus[x][y] = c;
  }

  const int kMaxMask = (1 << n);

  vector<vector<int>> dp(kMaxMask, vector<int>(n, -kInf64));

  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = a[i];
  }

  for (int mask = 0; mask < kMaxMask; mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) continue;
      const int nxt = mask - (1 << i);
      for (int j = 0; j < n; j++) {
        if ((nxt & (1 << j)) == 0) continue;
        dp[mask][i] = max(dp[mask][i], dp[nxt][j] + bonus[j][i] + a[i]);
      }
    }
  }

  int ans = 0;
  for (int mask = 0; mask < kMaxMask; mask++) {
    if (__builtin_popcount(mask) != m) continue;
    ans = max(ans, *max_element(dp[mask].begin(), dp[mask].end()));
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
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}