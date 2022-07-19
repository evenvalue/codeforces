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

inline void solution() {
  const int n = read::Int();
  vector<int> a(n + 2, kInf);
  for (int i = 1; i <= n; i++) {
    a[i] = read::Int();
  }

  int ans = kInf;

  //case 1: distance 1 (neighbours)
  for (int i = 1; i < n; i++) {
    const int x = max(a[i], a[i + 1]), y = min(a[i], a[i + 1]);
    if (2 * y < x) {
      ans = min(ans, (x + 1) / 2);
    } else {
      ans = min(ans, (x - y) + (4 * y - 2 * x + 2) / 3);
    }
  }

  //case 2: distance 2 (neighbour's neighbour)
  for (int i = 2; i < n; i++) {
    ans = min(ans, (a[i - 1] + a[i + 1] + 1) / 2);
  }

  //case 3: distance >= 3
  const int mini1 = *min_element(a.begin(), a.end());
  a.erase(find_if(a.begin(), a.end(), [&](const int x) {
    return (x == mini1);
  }));
  const int mini2 = *min_element(a.begin(), a.end());
  ans = min(ans, (mini1 + 1) / 2 + (mini2 + 1) / 2);

  cout << ans << '\n';
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