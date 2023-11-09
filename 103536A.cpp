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
constexpr int64 kInf64 = 1e18 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read::Int();
  const int k = min(n, read::Int());

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

  auto len = [&](const int l, const int r) {
    return r - l + 1;
  };

  vector<vector<int64>> dp(2, vector<int64>(n + 1, kInf64));
  function<void(int, int, int, int)> dnc = [&](const int l, const int r, const int optl, const int optr) {
    if (r < l) return;
    const int mid = (l + r) / 2;
    pair<int64, int> best{kInf64, -1};
    for (int i = optl; i <= min(mid, optr); i++) {
      const int64 cost = dp[0][i - 1] + sum(i, mid) * len(i, mid);
      if (cost < best.first) {
        best.first = cost;
        best.second = i;
      }
    }
    dp[1][mid] = best.first;
    const int opt = best.second;
    dnc(l, mid - 1, optl, opt);
    dnc(mid + 1, r, opt, optr);
  };

  for (int i = 1; i <= n; i++) {
    dp[0][i] = sum(1, i) * len(1, i);
  }

  for (int guards = 2; guards <= k; guards++) {
    dnc(guards, n, guards - 1, n);
    swap(dp[0], dp[1]);
  }

  cout << dp[0][n] << '\n';
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