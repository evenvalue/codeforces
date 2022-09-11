#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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

struct node {
  int c = 0;
  int p = 0;
  int q = 0;

  node &operator+=(const node &other) {
    p += other.p;
    q += other.q;
    return *this;
  }
};

inline void solution() {
  const int n = read::Int();
  vector<node> nodes(n);
  for (node &x : nodes) {
    const int a = read::Int(), b = read::Int(), c = read::Int();
    x.c = a;
    x.p = (b == 0 and c == 1);
    x.q = (b == 1 and c == 0);
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1, y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int64 ans = 0;

  function<node(int, int)> dfs = [&](const int x, const int p) {
    node &cur = nodes[x];
    cur.c = min(cur.c, nodes[p].c);
    for (const int y : g[x]) {
      if (y == p) continue;
      cur += dfs(y, x);
    }
    const int satisfy = min(cur.p, cur.q);
    ans += cur.c * 1LL * satisfy;
    cur.p -= satisfy;
    cur.q -= satisfy;
    return cur;
  };

  dfs(0, 0);

  cout << (nodes[0].p != nodes[0].q ? -1 : 2 * ans) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}