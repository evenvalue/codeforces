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

struct edge {
  int x;
  int y;
  int64 w;
};

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  const int l = read::Int();
  const int s = read::Int();
  const int t = read::Int();

  vector<vector<int>> g(n);
  vector<edge> edges(m);
  for (int i = 0, erased_count = 0; i < m; i++) {
    edges[i].x = read::Int();
    edges[i].y = read::Int();
    edges[i].w = read::Int();
    if (edges[i].w == 0) {
      edges[i].w = -(++erased_count);
    }
    g[edges[i].x].push_back(i);
    g[edges[i].y].push_back(i);
  }

  const int k = count_if(edges.begin(), edges.end(), [](const edge &e) {
    return e.w < 0;
  });

  auto get_weight = [&](const int i, const int ones) -> int64 {
    assert(0 <= ones and ones <= k);
    if (edges[i].w > 0) {
      return edges[i].w;
    } else {
      return (-edges[i].w <= ones ? 1 : kInf);
    }
  };

  vector<int64> dist(n, kInf64);
  set<pair<int64, int>> q;

  auto dijkstra = [&](const int ones) -> int64 {
    fill(dist.begin(), dist.end(), kInf);
    dist[s] = 0;
    q.emplace(0, s);
    while (not q.empty()) {
      const auto [d, z] = *q.begin();
      q.erase(q.begin());
      if (d > dist[z]) continue;
      for (const int i : g[z]) {
        auto [x, y, w] = edges[i];
        y = x ^ y ^ z;
        w = get_weight(i, ones);
        if (dist[z] + w <= dist[y]) {
          if (const auto it = q.find({dist[y], y}); it != q.end())
            q.erase(it);
          dist[y] = dist[z] + w;
          q.emplace(dist[y], y);
        }
      }
    }
    return dist[t];
  };

  const int64 d1 = dijkstra(k);
  const int64 dinf = dijkstra(0);
  debug(d1, dinf);

  if (not(d1 <= l and l <= dinf)) {
    cout << "NO\n";
    return;
  }

  int lo = 0, hi = k;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    const int64 dmid = dijkstra(mid);
    if (l < dmid) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  const int64 dans = dijkstra(lo);
  for (auto &[x, y, w] : edges) {
    if (w > 0) continue;
    if (-w < lo) {
      w = 1;
    } else if (-w == lo) {
      w = l - dans + 1;
    } else {
      w = kInf;
    }
  }

  cout << "YES\n";
  for (const auto &[x, y, w] : edges) {
    cout << x << ' ' << y << ' ' << w << '\n';
  }
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