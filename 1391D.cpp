#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector<string> transpose(const vector<string> &v, int &n, int &m) {
  swap(n, m);
  vector<string> new_v(n, string(m, '0'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      new_v[i][j] = v[j][i];
    }
  }
  return new_v;
}

vector<int> convert(const vector<string> &v, const int n, const int m) {
  assert(0 < n and n <= m);
  assert(n <= 3);
  vector<int> a(m);
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      a[col] = (1 << row) * (v[row][col] - '0');
    }
  }
  return a;
}

bool is_valid(const int mask1, const int mask2, const int n) {
  int a[2][n];
  for (int i = 0; i < n; i++) {
    a[1][i] = ((mask1 & (1 << i)) ? 1 : 0);
    a[2][i] = ((mask2 & (1 << i)) ? 1 : 0);
  }
  for (int i = 1; i < n; i++) {
    int s = a[1][i - 1] + a[2][i - 1] + a[1][i] + a[2][i];
    if ((s & 1) == 0) return false;
  }
  return true;
}

inline void solution() {
  int n = read::Int(), m = read::Int();
  vector<string> v = read::Vec<string>(n);

  if (min(n, m) >= 4) {
    cout << -1 << '\n';
    return;
  }

  const vector<int> a = convert((n > m) ? transpose(v, n, m) : v, n, m);

  vector<vector<int>> dp(m, vector<int>(1 << n, kInf));
  for (int mask = 0; mask < (1 << n); mask++) {
    dp[0][mask] = __builtin_popcount(mask ^ a[0]);
  }
  for (int col = 1; col < m; col++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int last_mask = 0; last_mask < (1 << n); last_mask++) {
        if (not is_valid(mask, last_mask, n)) continue;
        dp[col][mask] = min(dp[col][mask], dp[col - 1][last_mask] + __builtin_popcount(mask ^ a[col]));
      }
    }
  }

  cout << *min_element(dp[m - 1].begin(), dp[m - 1].end()) << '\n';
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