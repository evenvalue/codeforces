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

struct Point {
  int i;
  int x;
  int y;
};

vector<vector<pair<int, int64>>> build_graph(vector<Point> points) {
  const int n = points.size();
  vector<vector<pair<int, int64>>> g(n);

  sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
    return p1.x < p2.x;
  });

  for (int i = 0; i < n - 1; i++) {
    const int x = points[i].i;
    const int y = points[i + 1].i;
    const int w = points[i + 1].x - points[i].x;
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
    return p1.y < p2.y;
  });

  for (int i = 0; i < n - 1; i++) {
    const int x = points[i].i;
    const int y = points[i + 1].i;
    const int w = points[i + 1].y - points[i].y;
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  return g;
}

pair<vector<int64>, vector<int>> dijkstra(const vector<vector<pair<int, int64>>> &g, const vector<int> &s) {
  const int n = (int) g.size();

  vector<int64> d(n, kInf);
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

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();

  Point source{};
  Point finish{};

  source.x = read::Int();
  source.y = read::Int();
  finish.x = read::Int();
  finish.y = read::Int();

  vector<Point> points(m + 1);
  points[0] = source;
  for (int i = 1; i <= m; i++) {
    points[i].x = read::Int();
    points[i].y = read::Int();
  }
  for (int i = 0; i <= m; i++) {
    points[i].i = i;
  }

  const auto g = build_graph(points);
  const auto dist = dijkstra(g, {0}).first;

  int64 ans = kInf64;
  for (int i = 0; i <= m; i++) {
    const int d = abs(finish.x - points[i].x) + abs(finish.y - points[i].y);
    ans = min(ans, d + dist[i]);
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