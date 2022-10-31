#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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
constexpr int64 kInf64 = 1e17 + 10;
constexpr int kMod = 1e9 + 7;

inline void solution() {
  const int n = read::Int(), m = read::Int(), k = read::Int();
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = read::Int();
  }

  vector<int64> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  auto sum = [&](const int l, const int r) {
    return pref[r] - pref[l - 1];
  };

  vector<vector<int64>> dp(n + 1, vector<int64>(k + 1, -kInf64));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int j = 1; j <= k; j++) {
      if (j * m > i) break;
      dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + sum(i - m + 1, i));
    }
  }

  cout << dp[n][k] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}