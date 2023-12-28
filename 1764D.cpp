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

int binpow(int64 a, int64 b, int m) {
  a %= m;
  int64 res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

inline void solution() {
  const int n = read::Int();
  const int p = read::Int();
  const int t = n / 2;

  vector<int> fact(kMaxN);
  fact[0] = 1;
  for (int i = 1; i < kMaxN; i++) {
    fact[i] = (fact[i - 1] * 1LL * i) % p;
  }

  vector<int> inv(kMaxN);
  for (int i = 0; i < n; i++) {
    inv[i] = binpow(fact[i], p - 2, p);
  }

  auto nCr = [&](const int n, const int r) -> int {
    if (r > n) return 0;
    const int div = (inv[r] * 1LL * inv[n - r]) % p;
    return (fact[n] * 1LL * div) % p;
  };

  int64 ans = 0;
  for (int i = t; i <= n - 2; i++) {
    for (int j = 0; j <= n - i - 2; j++) {
      const int part1 = nCr(n - i - 2, j);
      const int part2 = fact[i + j - 1];
      const int part3 = 2 * t - i;
      const int add = (((part1 * 1LL * part2) % p) * part3) % p;
      ans += add;
      ans %= p;
    }
  }

  ans += (n % 2 == 0 ? fact[n - 2] : 0);
  ans %= p;

  cout << (n * 1LL * ans) % p << '\n';
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