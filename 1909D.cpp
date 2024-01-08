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
  const int k = read::Int();

  vector<int> a = read::Vec<int>(n);
  sort(a.begin(), a.end());

  if (a[0] == a.back()) {
    cout << 0 << '\n';
    return;
  }

  if (a[0] <= k and a.back() >= k) {
    cout << -1 << '\n';
    return;
  }

  function<int(int, int)> gcd_big = [&](const int x, const int y) {
    if (x == y) return x;
    const int c = (y - k - 1) / (x - k);
    return gcd_big(y - c * (x - k), x);
  };

  function<int(int, int)> gcd_small = [&](const int x, const int y) {
    if (x == y) return x;
    const int c = (k - x - 1) / (k - y);
    return gcd_small(y, x + c * (k - y));
  };

  const auto &gcd_like = (a[0] > k ? gcd_big : gcd_small);

  int g = a[0];
  for (const int x : a) {
    g = gcd_like(g, x);
  }

  int ans = 0;
  for (const int x : a) {
    ans += (x - g) / (g - k);
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