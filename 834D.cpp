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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

struct Window {
  int l = 1;
  int r = 0;
  int64 cost = 0;
};

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = read::Int();
  }

  vector<int> freq(n + 1);

  Window window;
  auto shift = [&](const int ql, const int qr) {
    while (ql < window.l) {
      window.l--;
      freq[a[window.l]]++;
      if (freq[a[window.l]] == 1) window.cost++;
    }
    while (window.r < qr) {
      window.r++;
      freq[a[window.r]]++;
      if (freq[a[window.r]] == 1) window.cost++;
    }
    while (window.l < ql) {
      if (freq[a[window.l]] == 1) window.cost--;
      freq[a[window.l]]--;
      window.l++;
    }
    while (qr < window.r) {
      if (freq[a[window.r]] == 1) window.cost--;
      freq[a[window.r]]--;
      window.r--;
    }
  };

  vector<vector<int64>> dp(2, vector<int64>(n + 1, -kInf64));
  function<void(int, int, int, int)> dnc = [&](const int l, const int r, const int optl, const int optr) {
    if (r < l) return;
    const int mid = (l + r) / 2;
    pair<int64, int> best{-kInf64, -1};
    for (int i = optl; i <= min(mid, optr); i++) {
      shift(i, mid);
      const int64 cost = dp[0][i - 1] + window.cost;
      if (cost > best.first) {
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
    shift(1, i);
    dp[0][i] = window.cost;
  }

  debug(dp[0]);
  for (int seg = 2; seg <= k; seg++) {
    dnc(seg, n, seg - 1, n);
    debug(dp[1]);
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