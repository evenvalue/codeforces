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
  int a = Read::Int();
  int b = Read::Int();
  int r = Read::Int();

  if (a < b) swap(a, b);

  int start = -1;
  for (int i = 61; i >= 0; i--) {
    const int bit_a = a & (1LL << i);
    const int bit_b = b & (1LL << i);
    if (bit_a == bit_b) continue;
    start = i;
    break;
  }

  int x = 0;
  for (int i = start - 1; i >= 0; i--) {
    const int bit_a = a & (1LL << i);
    const int bit_b = b & (1LL << i);
    if (bit_a > 0 and bit_b == 0) {
      if (x + bit_a <= r) {
        x += bit_a;
      }
    }
  }

  cout << abs((a ^ x) - (b ^ x)) << '\n';
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