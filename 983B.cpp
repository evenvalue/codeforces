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
  const vector<int> a = read::Vec<int>(n);

  vector<vector<int>> f(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    f[i][i] = a[i];
  }
  for (int size = 2; size <= n; size++) {
    for (int l = 0; l <= n - size; l++) {
      const int r = l + size - 1;
      f[l][r] = f[l][r - 1] ^ f[l + 1][r];
    }
  }

  vector<vector<int>> best = f;
  for (int size = 2; size <= n; size++) {
    for (int l = 0; l <= n - size; l++) {
      const int r = l + size - 1;
      best[l][r] = max({best[l][r], best[l + 1][r], best[l][r - 1]});
    }
  }

  int q = read::Int();
  while (q--) {
    const int l = read::Int() - 1;
    const int r = read::Int() - 1;
    cout << best[l][r] << '\n';
  }
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