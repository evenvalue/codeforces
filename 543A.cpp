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

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  const int b = read::Int();
  const int mod = read::Int();

  vector<int> a = read::Vec<int>(n);
  a.insert(a.begin(), 0);

  vector<vector<vector<int64>>> ways(2, vector<vector<int64>>(m + 1, vector<int64>(b + 1)));

  ways[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int lines = 0; lines <= m; lines++) {
      for (int bugs = 0; bugs <= b; bugs++) {
        ways[1][lines][bugs] = ways[0][lines][bugs];
        if (lines >= 1 and bugs >= a[i]) ways[1][lines][bugs] += ways[1][lines - 1][bugs - a[i]];
        ways[1][lines][bugs] %= mod;
      }
    }
    swap(ways[0], ways[1]);
  }

  int64 ans = 0;
  for (int bugs = 0; bugs <= b; bugs++) {
    ans += ways[0][m][bugs];
    ans %= mod;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);r
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}