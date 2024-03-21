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

int ask(const int x, const string &s) {
  cout << "? " << x + 1 << ' ' << s << endl;
  return Read::Int();
}

void say(const string &s) {
  cout << "! " << s << endl;
}

inline void solution() {
  const int n = Read::Int();

  vector<int> deg(n);
  for (int x = 0; x < n; x++) {
    string s(n, '1');
    s[x] = '0';
    deg[x] = ask(x, s);
  }

  vector<int> nodes(n);
  iota(nodes.begin(), nodes.end(), 0);
  sort(nodes.begin(), nodes.end(), [&](const int i, const int j) {
    return deg[i] > deg[j];
  });

  int sum = 0;

  string s(n, '0');
  for (int i = 1; i <= n; i++) {
    s[nodes[i - 1]] = '1';
    sum += deg[nodes[i - 1]];
    if (sum == i * (i - 1) / 2 + i * (n - i)) {
      break;
    }
  }

  say(s);
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