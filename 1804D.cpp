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

int max_occupied(const string &s) {
  const int n = s.size();

  int two = n / 4;
  int occupied = 0;

  vector<bool> taken(n);
  for (int i = 1; i < n and two > 0; i++) {
    if (s[i - 1] == '1' and s[i] == '1') continue;
    occupied += (s[i - 1] == '1' or s[i] == '1');
    taken[i - 1] = true;
    taken[i] = true;
    two--;
    i++;
  }

  for (int i = 0; i < n; i++) {
    if (taken[i]) continue;
    occupied += (s[i] == '1');
  }

  return occupied - two;
}

int min_occupied(const string &s) {
  const int n = s.size();

  int two = n / 4;
  int occupied = 0;

  vector<bool> taken(n);
  for (int i = 1; i < n and two > 0; i++) {
    if (s[i] == '1' and s[i - 1] == '1') {
      taken[i] = true;
      taken[i - 1] = true;
      two--;
      occupied++;
      i++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (taken[i]) continue;
    occupied += (s[i] == '1');
  }

  return occupied;
}

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();

  const vector<string> building = read::Vec<string>(n);

  int mn = 0;
  int mx = 0;
  for (const string &floor : building) {
    mn += min_occupied(floor);
    mx += max_occupied(floor);
  }

  cout << mn << ' ' << mx << '\n';
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