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
constexpr int kMaxN = 4e3 + 5;

using bit = bitset<kMaxN>;

void knapsack(const vector<int> &a, bit &sack) {
  const int n = a.size();
  for (const int x : a) {
    sack |= (sack << x);
  }
}

inline void solution(bit &sack) {
  const int n = read::Int();

  const vector<int> p = read::Vec<int>(2 * n);
  vector<int> forced;
  for (int mx = 0; const int x : p) {
    if (x > mx) {
      forced.push_back(0);
      mx = x;
    }
    forced.back()++;
  }

  knapsack(forced, sack);
  cout << (sack[n] ? "YES" : "NO") << '\n';

  for (int i = 1; i <= 2 * n; i++) {
    sack[i] = false;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  bit sack;
  sack[0] = true;

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution(sack);
  }
}