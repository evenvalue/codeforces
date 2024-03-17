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

namespace Read {
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
}//namespace Read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = Read::Int();
  const int m = Read::Int();

  auto hash = [&](const int r, const int c) {
    return m * r + c;
  };

  auto nbr = [&](const int r, const int c, const char cur) {
    int x = r, y = c;
    if (cur == 'U') x--;
    if (cur == 'D') x++;
    if (cur == 'L') y--;
    if (cur == 'R') y++;
    if (x < 0 or x >= n) return -1;
    if (y < 0 or y >= m) return -1;
    return hash(x, y);
  };

  vector<basic_string<int>> g(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      const char c = Read::Char();
      const int x = hash(i, j);
      const int y = nbr(i, j, c);
      if (y != -1) g[x].push_back(y);
    }
  }

  vector<int> dp(n * m);
  vector<int> head(n * m);
  iota(head.begin(), head.end(), 0);

  function<void(int)> dfs = [&](const int start) {
    vector<int> order;
    order.push_back(start);

    for (int i = 0; i < order.size(); i++) {
      const int x = order[i];
      dp[x] = -1;
      for (const int y : g[x]) {
        if (dp[y] > 0) {
          dp[x] = dp[head[y]] + 1;
          order.pop_back();
          break;
        }
        if (dp[y] == 0) {
          order.push_back(y);
        }
      }
    }

    while (not order.empty()) {
      const int x = order.back();
      order.pop_back();
      for (const int y : g[x]) {
        if (dp[y] == -1) {
          head[x] = y;
        } else {
          if (head[y] != y) {
            head[x] = head[y];
            dp[x] = dp[y] + 1;
          } else {
            dp[x] = dp[head[y]] + 1;
          }
        }
      }
      dp[x] = max(dp[x], 1);
    }
  };

  for (int i = 0; i < n * m; i++) {
    if (dp[i] != 0) continue;
    dfs(i);
  }

  const int x = distance(dp.begin(), max_element(dp.begin(), dp.end()));
  cout << (x / m) + 1 << ' ' << (x % m) + 1 << ' ' << dp[x] << '\n';
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