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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

int get_height(const int red, const int green) {
  auto check = [&](int height) {
    for (int i = height, r = red, g = green; i > 0; i--) {
      if (r < g) swap(r, g);
      if (r < i) return false;
      r -= i;
    }
    return true;
  };

  int lo = 0, hi = 900;
  while (lo < hi) {
    const int mid = (lo + hi + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  return lo;
}

inline void solution() {
  const int red = read::Int();
  const int green = read::Int();
  const int height = get_height(red, green);

  vector<vector<int>> dp(2, vector<int>(red + 1));
  dp[0][0] = 1;

  for (int h = 1; h <= height; h++) {
    for (int r = 0; r <= red; r++) {
      dp[1][r] = dp[0][r] + (r >= h ? dp[0][r - h] : 0);
      dp[1][r] -= (dp[1][r] >= kMod ? kMod : 0);
    }
    debug(h, dp[1]);
    swap(dp[0], dp[1]);
  }

  const int blocks = height * (height + 1) / 2;
  const int min_red = max(0, blocks - green);

  int ans = 0;
  for (int r = min_red; r <= red; r++) {
    ans += dp[0][r];
    ans -= (ans >= kMod ? kMod : 0);
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