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
  const int k = read::Int();

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> sz(n);
  vector<bool> decomposed(n);

  function<int(int, int)> subtree_size = [&](const int x, const int p) {
    sz[x] = 1;
    for (const int y : g[x]) {
      if (decomposed[y] or y == p) continue;
      sz[x] += subtree_size(y, x);
    }
    return sz[x];
  };

  function<int(int, int, int)> centroid = [&](const int x, const int p, const int size) {
    int c = x;
    for (const int y : g[x]) {
      if (decomposed[y] or y == p) continue;
      if (2 * sz[y] < size) continue;
      c = centroid(y, x, size);
      break;
    }
    return c;
  };

  function<vector<int>(int, int)> calc_edges = [&](const int head, const int root) {
    vector<int> edges;
    function<void(int, int, int)> dfs = [&](const int x, const int p, const int d) {
      if (d > k) return;
      edges.push_back(d);
      for (const int y : g[x]) {
        if (y == p or decomposed[y]) continue;
        dfs(y, x, d + 1);
      }
    };
    dfs(head, root, 1);
    return edges;
  };

  struct Paths {
    int gen = -1;//generation
    int way = 0; //ways
  };

  int64 ans = 0;
  vector<Paths> dist(n + 1);

  function<void(int)> decompose = [&](int x) {
    x = centroid(x, -1, subtree_size(x, -1));
    decomposed[x] = true;

    dist[0] = {x, 1};

    for (const int y : g[x]) {
      if (decomposed[y]) continue;
      const vector<int> edges = calc_edges(y, x);
      for (const int d : edges) {
        if (dist[k - d].gen != x) continue;
        ans += dist[k - d].way;
      }
      for (const int d : edges) {
        if (dist[d].gen != x) {
          dist[d] = {x, 0};
        }
        dist[d].way++;
      }
    }

    for (const int y : g[x]) {
      if (decomposed[y]) continue;
      decompose(y);
    }
  };

  decompose(0);
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