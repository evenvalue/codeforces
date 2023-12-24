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
constexpr int kAlphaSize = 26;

using vec2d = vector<vector<int>>;
using vec3d = vector<vec2d>;

inline void solution() {
  string s = '-' + read::String();
  const int n = s.size() - 1;

  const int k = read::Int();
  const int m = read::Int();

  auto to_int = [](const char c) {
    assert('a' <= c and c <= 'z');
    return c - 'a';
  };

  vector<vector<int>> bonus(kAlphaSize, vector<int>(kAlphaSize));
  for (int i = 0; i < m; i++) {
    const int x = to_int(read::Char());
    const int y = to_int(read::Char());
    bonus[x][y] = read::Int();
  }

  vec3d dp(k + 1, vec2d(n + 1, vector<int>(kAlphaSize, -kInf)));

  for (int moves = 0; moves <= k; moves++) {
    for (int x = 0; x < kAlphaSize; x++) {
      dp[moves][0][x] = 0;
    }
  }

  dp[0][1][to_int(s[1])] = 0;
  for (int moves = 1; moves <= k; moves++) {
    for (int x = 0; x < kAlphaSize; x++) {
      dp[moves][1][x] = 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    const int cur = to_int(s[i]);
    const int prev = to_int(s[i - 1]);
    dp[0][i][cur] = dp[0][i - 1][prev] + bonus[prev][cur];
  }

  for (int moves = 1; moves <= k; moves++) {
    for (int i = 2; i <= n; i++) {
      for (int x = 0; x < kAlphaSize; x++) {
        const int play = (to_int(s[i]) != x);

        dp[moves][i][x] = dp[moves - 1][i][x];
        for (int y = 0; y < kAlphaSize; y++) {
          dp[moves][i][x] = max(dp[moves][i][x], dp[moves - play][i - 1][y] + bonus[y][x]);
        }
      }
    }
  }

  cout << *max_element(dp[k][n].begin(), dp[k][n].end()) << '\n';
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