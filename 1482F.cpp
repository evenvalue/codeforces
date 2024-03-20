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

auto dijkstra(const vector<vector<pair<int, int>>> &g, vector<int64> &d) {
  const int n = (int) g.size();

  vector<bool> visit(n);

  for (int i = 0; i < n; i++) {
    int x = -1;
    int64 dist = kInf64;
    for (int y = 0; y < n; y++) {
      if (visit[y]) continue;
      if (d[y] <= dist) {
        x = y;
        dist = d[y];
      }
    }
    visit[x] = true;
    for (const auto &[y, w] : g[x]) {
      if (d[y] <= d[x] + w) continue;
      d[y] = d[x] + w;
    }
  }

  return d;
}

struct edge {
  int x{};
  int y{};
  int w{};
  bool useful = false;
};

inline void solution() {
  const int n = Read::Int();
  const int m = Read::Int();

  vector<edge> edges(m);
  vector<vector<pair<int, int>>> g(n);
  vector<vector<int64>> d(n, vector<int64>(n, kInf64));

  for (auto &[x, y, w, _] : edges) {
    x = Read::Int() - 1;
    y = Read::Int() - 1;
    w = Read::Int();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
    d[x][y] = d[y][x] = w;
  }

  for (int x = 0; x < n; x++) {
    d[x][x] = 0;
  }

  for (int k = 0; k < n; k++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        d[x][y] = min(d[x][y], d[x][k] + d[k][y]);
      }
    }
  }

  vector<vector<int64>> req(n, vector<int64>(n, kInf64));
  int q = Read::Int();
  while (q--) {
    const int x = Read::Int() - 1;
    const int y = Read::Int() - 1;
    const int64 l = Read::Int();
    req[x][y] = req[y][x] = min(req[x][y], -l);
  }

  for (int v = 0; v < n; v++) {
    dijkstra(g, req[v]);
    for (auto &[x, y, w, useful] : edges) {
      useful |= (req[v][x] <= -w - d[v][y]) or (req[v][y] <= -w - d[v][x]);
    }
  }

  int ans = 0;
  for (const auto e : edges) {
    ans += e.useful;
  }

  cout << ans << '\n';
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