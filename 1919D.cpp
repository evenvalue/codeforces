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
  vector<int> a = read::Vec<int>(n);

  const int zero = count(a.begin(), a.end(), 0);

  if (zero != 1) {
    cout << "NO\n";
    return;
  }

  vector<bool> satisfied(n);

  vector<pair<int, int>> stk;
  for (int i = 0; i < n; i++) {
    while (not stk.empty() and stk.back().first > a[i]) {
      if (stk.back().first == a[i] + 1) {
        satisfied[stk.back().second] = true;
      }
      stk.pop_back();
    }
    stk.emplace_back(a[i], i);
  }

  stk.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (not stk.empty() and stk.back().first > a[i]) {
      if (stk.back().first == a[i] + 1) {
        satisfied[stk.back().second] = true;
      }
      stk.pop_back();
    }
    stk.emplace_back(a[i], i);
  }

  const int foo = std::count(satisfied.begin(), satisfied.end(), false);

  cout << (foo == 1 ? "YES" : "NO") << '\n';
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