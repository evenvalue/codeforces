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
  const vector<int> cost = read::Vec<int>(n);

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<vector<int>> dp(n, vector<int>(4, -kInf64));

  function<void(int, int)> dfs = [&](const int x, const int p) {
    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x);
    }

    //dp[x][0] -> take no child
    //dp[x][1] -> take one child
    //dp[x][2] -> take two children
    //dp[x][3] -> take three or more children

    vector<int> take;
    for (const int y : g[x]) {
      if (y == p) continue;

      const int op1 = dp[y][0];
      const int op2 = dp[y][1] - cost[y];
      const int op3 = dp[y][2];
      const int op4 = dp[y][3];

      const int best = max({op1, op2, op3, op4});
      take.push_back(best);
    }

    sort(take.rbegin(), take.rend());

    dp[x][0] = cost[x];

    if (take.size() >= 1) dp[x][1] = take[0] + cost[x];
    if (take.size() >= 2) dp[x][2] = take[0] + take[1] + cost[x];
    if (take.size() >= 3) {
      int best = take[0] + take[1] + take[2];
      for (int i = 3, sum = best; i < take.size(); i++) {
        sum += take[i];
        best = max(best, sum);
      }
      dp[x][3] = best + cost[x];
    }
  };

  dfs(0, -1);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (const int pick : {0, 1, 3}) {
      ans = max(ans, dp[i][pick]);
    }
    ans = max(ans, dp[i][2] - cost[i]);
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