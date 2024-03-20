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

pair<vector<int64>, vector<int>> dijkstra(const vector<vector<pair<int, int64>>> &g, const vector<int> &s) {
  const int n = (int) g.size();

  vector<int64> d(n, kInf64);
  vector<int> p(n, -1);
  min_heap<pair<int64, int>> q;

  for (const int x : s) {
    d[x] = 0;
    q.emplace(0, x);
  }

  while (not q.empty()) {
    const auto [dist, x] = q.top();
    q.pop();
    if (d[x] < dist) continue;
    for (const auto &[y, w] : g[x]) {
      if (d[y] <= d[x] + w) continue;
      d[y] = d[x] + w;
      p[y] = x;
      q.emplace(d[y], y);
    }
  }

  return make_pair(d, p);
}

struct Column {
  int r;
  int c;
  int x;

  bool operator<(const Column &other) const {
    return x < other.x;
  }
};

inline void solution() {
  const auto n = Read::Int();
  const auto m = Read::Int();
  const auto cost = Read::Vec<int>(n);
  const auto pokemon = Read::VecVec<int>(n, m);

  vector<vector<pair<int, int64>>> g(n * (m + 1));
  for (int x = 0; x < n; x++) {
    for (int y = x * m; y < (x + 1) * m; y++) {
      g[x + n * m].emplace_back(y, 0);
      g[y].emplace_back(x + n * m, cost[x]);
    }
  }

  vector<vector<Column>> col(m, vector<Column>(n));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      col[j][i] = {i, j, pokemon[i][j]};
    }
    auto &c = col[j];
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < n - 1; i++) {
      const auto [r1, c1, v1] = c[i];
      const auto [r2, c2, v2] = c[i + 1];

      const int x1 = r1 * m + c1;
      const int x2 = r2 * m + c2;

      g[x1].emplace_back(x2, v1 - v2);
      g[x2].emplace_back(x1, 0);
    }
  }

  cout << dijkstra(g, {n * m}).first.back() << '\n';
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