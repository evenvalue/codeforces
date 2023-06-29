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
constexpr int kMaxN = 2e5 + 10;

vector<int> bfs(const vector<vector<int>> &g, const vector<int> &sources) {
  const int n = g.size();

  queue<int> q;
  vector<int> dist(n, kInf);

  for (const int x : sources) {
    q.push(x);
    dist[x] = 0;
  }

  while (not q.empty()) {
    const int x = q.front();
    for (const int y : g[x]) {
      if (dist[y] != kInf) continue;
      dist[y] = dist[x] + 1;
      q.push(y);
    }
    q.pop();
  }

  return dist;
}

int furthest_node(const vector<int> &dist) {
  return max_element(dist.begin(), dist.end()) - dist.begin();
}

int furthest_dist(const vector<int> &dist) {
  return *max_element(dist.begin(), dist.end());
}

void print_nodes(const int x, const int y, int z) {
  if (z == x or z == y) {
    if (x != 0 and y != 0) z = 0;
    if (x != 1 and y != 1) z = 1;
    if (x != 2 and y != 2) z = 2;
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
}

inline void solution() {
  const int n = read::Int();

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  const int root = 0;
  const vector<int> dr = bfs(g, {root});

  const int x = furthest_node(dr);
  const vector<int> dx = bfs(g, {x});

  const int y = furthest_node(dx);
  const vector<int> dy = bfs(g, {y});

  vector<int> diameter;
  for (int i = 0; i < n; i++) {
    if (dx[i] + dy[i] == dx[y]) diameter.push_back(i);
  }

  const vector<int> dd = bfs(g, diameter);
  cout << dx[y] + furthest_dist(dd) << '\n';

  print_nodes(x, y, furthest_node(dd));
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