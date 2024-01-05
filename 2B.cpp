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

pair<int, string> best_path(const vector<vector<int>> &grid) {
  const int n = grid.size();

  vector<vector<int>> dp(n, vector<int>(n));
  vector<vector<int>> par(n, vector<int>(n, -1));

  dp[0][0] = grid[0][0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
    dp[0][i] = dp[0][i - 1] + grid[0][i];
    par[i][0] = 0;
    par[0][i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (dp[i - 1][j] < dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j] + grid[i][j];
        par[i][j] = 0;
      } else {
        dp[i][j] = dp[i][j - 1] + grid[i][j];
        par[i][j] = 1;
      }
    }
  }

  int ans = (dp[n - 1][n - 1] < 0 ? 1 : dp[n - 1][n - 1]);
  string path;

  for (int x = n - 1, y = n - 1; par[x][y] != -1;) {
    path += (par[x][y] == 0 ? 'D' : 'R');
    const int cur = par[x][y];
    x -= 1 - cur;
    y -= cur;
  }

  reverse(path.begin(), path.end());
  return {ans, path};
}

inline void solution() {
  const int n = read::Int();
  vector<vector<int>> grid = read::VecVec<int>(n, n);

  vector<vector<int>> two(n, vector<int>(n));
  vector<vector<int>> five(n, vector<int>(n));
  vector<vector<int>> zero(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) {
        two[i][j] = kInf;
        five[i][j] = kInf;
        zero[i][j] = -kInf64;
        continue;
      } else {
        zero[i][j] = kInf;
      }
      while (grid[i][j] % 2 == 0) {
        two[i][j]++;
        grid[i][j] /= 2;
      }
      while (grid[i][j] % 5 == 0) {
        five[i][j]++;
        grid[i][j] /= 5;
      }
    }
  }

  auto ans = min({best_path(zero), best_path(two), best_path(five)});

  cout << ans.first << '\n';
  cout << ans.second << '\n';
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