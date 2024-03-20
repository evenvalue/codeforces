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

int ask(const int a, const int b, const int c, const int d) {
  cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
  const char ch = Read::Char();
  if (ch == '>') return 1;
  if (ch == '<') return -1;
  return 0;
}

void say(const int a, const int b) {
  cout << "! " << a << ' ' << b << endl;
}

inline void solution() {
  const int n = Read::Int();

  int first = 0;
  for (int i = 1; i < n; i++) {
    const int x = ask(first, first, i, i);
    if (x == -1) first = i;
  }

  vector<int> list = {first};
  for (int i = 0; i < n; i++) {
    if (i == first) continue;
    const int x = ask(first, list[0], first, i);
    if (x == 0) {
      list.push_back(i);
    } else if (x == -1) {
      list.clear();
      list.push_back(i);
    }
  }

  int second = list[0];
  for (int i = 1; i < list.size(); i++) {
    const int x = ask(second, second, list[i], list[i]);
    if (x == 1) second = list[i];
  }

  say(first, second);
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