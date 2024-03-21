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

template<typename T>
class CoordinateCompression {
  bool sorted = false;
  vector<T> v;

public:
  void add(const T &x) {
    v.push_back(x);
  }

  void compress() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sorted = true;
  }

  int get(const int x) {
    if (not sorted) assert(false);
    return distance(v.begin(), lower_bound(v.begin(), v.end(), x));
  }

  int size() {
    return v.size();
  }
};

struct edge {
  int x;
  int y;
  int i;
  int dir;
};

inline void solution() {
  const int n = Read::Int();

  vector<vector<int>> a(n);
  CoordinateCompression<int> cc;

  for (auto &v : a) {
    const int k = Read::Int();
    v = Read::Vec<int>(k);
    for (const auto x : v) {
      cc.add(x);
    }
  }

  cc.compress();
  for (auto &v : a) {
    for (auto &x : v) {
      x = cc.get(x);
    }
  }

  const int m = cc.size();

  vector<vector<pair<int, int>>> g(n + m);
  vector<edge> edges;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      const int x = a[i][j];
      g[i + m].emplace_back(x, edges.size());
      g[x].emplace_back(i + m, edges.size());
      edges.push_back({i + m, x, j, -1});
    }
  }

  for (const auto &v : g) {
    if (v.size() % 2 == 1) {
      cout << "NO\n";
      return;
    }
  }

  vector<int> next(n + m);
  function<void(int)> dfs = [&](const int x) {
    while (next[x] < g[x].size()) {
      const auto [y, i] = g[x][next[x]++];
      if (edges[i].dir != -1) continue;
      edges[i].dir = (edges[i].x == x);
      dfs(y);
    }
  };

  for (int x = 0; x < n + m; x++) {
    dfs(x);
  }

  vector<string> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = string(a[i].size(), '-');
  }

  for (const auto [x, y, i, d] : edges) {
    ans[x - m][i] = (d ? 'L' : 'R');
  }

  cout << "YES\n";
  for (const auto &s : ans) {
    cout << s << '\n';
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