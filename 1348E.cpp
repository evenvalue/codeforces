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

struct Shrub {
  int black;
  int white;
};

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  vector<Shrub> shrubs(n);
  for (auto &[b, w] : shrubs) {
    b = read::Int();
    w = read::Int();
  }

  vector<vector<bool>> dp(2, vector<bool>(k + 1));

  for (int black = 0, white = k; black <= k; black++, white--) {
    if (black > shrubs[0].black) continue;
    if (white > shrubs[0].white) continue;
    dp[0][black] = true;
  }

  for (int i = 1; i < n; i++) {
    const Shrub shrub = shrubs[i];
    dp[1] = dp[0];
    for (int black = 0, white = k; black <= k; black++, white--) {
      if (black <= shrub.black and white <= shrub.white) {
        dp[1][black] = true;
      }
      for (int b = 0, w = k; b <= k; b++, w--) {
        if (b > shrub.black) continue;
        if (w > shrub.white) continue;
        dp[1][black] = dp[1][black] or dp[0][(black - b + k) % k];
      }
    }
    swap(dp[0], dp[1]);
  }

  int64 total_black = 0;
  int64 total_white = 0;
  for (const auto [b, w] : shrubs) {
    total_black += b;
    total_white += w;
  }

  const int extra_black = total_black % k;
  const int extra_white = total_white % k;

  bool extra = false;
  for (int black = 0, white = k; black <= k; black++, white--) {
    if (extra_black < black) continue;
    if (extra_white < white) continue;
    extra |= dp[0][black];
  }

  cout << (total_black / k) + (total_white / k) + extra << '\n';
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