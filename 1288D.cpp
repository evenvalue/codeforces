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
  const int n = read::Int(), m = read::Int();
  const vector<vector<int>> a = read::VecVec<int>(n, m);

  vector<int> masks(1 << m);

  int i = 0, j = 0;

  auto clear = [&]() {
    for (int &mask : masks) {
      mask = 0;
    }
  };

  auto check = [&](const int x) -> bool {
    for (int row = 0; row < n; row++) {
      int num = 0;
      for (int col = 0; col < m; col++) {
        num += ((a[row][col] >= x ? (1 << col) : 0));
      }
      masks[num] = row + 1;
    }

    for (int mask1 = 0; mask1 < (1 << m); mask1++) {
      if (masks[mask1] == 0) continue;
      for (int mask2 = mask1; mask2 < (1 << m); mask2++) {
        if (masks[mask2] == 0) continue;
        if ((mask1 | mask2) == ((1 << m) - 1)) {
          i = masks[mask1], j = masks[mask2];
          clear();
          return true;
        }
      }
    }

    clear();
    return false;
  };

  int lo = -1, hi = 1e9 + 10;
  while (lo < hi) {
    const int mid = (lo + hi + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << i << ' ' << j << '\n';
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