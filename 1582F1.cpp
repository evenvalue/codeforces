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

  const int kMaxA = *max_element(a.begin(), a.end());
  const int kMaxXor = 2 * kMaxA;

  vector<bool> possible(kMaxXor + 1);
  vector<int> unseen(kMaxXor + 1, kMaxA);
  vector<vector<int>> push(kMaxA + 1, {0});

  possible[0] = true;

  for (const int x : a) {
    for (const int val : push[x]) {
      const int nxt = val ^ x;
      while (unseen[nxt] > x) {
        push[unseen[nxt]].push_back(nxt);
        unseen[nxt]--;
      }
      possible[nxt] = true;
    }
    push[x].clear();
  }

  const int k = count(possible.begin(), possible.end(), true);
  cout << k << '\n';
  for (int i = 0; i <= kMaxXor; i++) {
    if (possible[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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