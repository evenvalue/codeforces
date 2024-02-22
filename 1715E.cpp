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

struct Line {
  int64 m, c;
  mutable int64 p;
  bool operator<(const Line &other) const {
    return m < other.m;
  }
  bool operator<(int64 x) const {
    return p < x;
  }
};

struct LineContainer : std::multiset<Line, std::less<>> {
private:
  static const int64 kInfinity = LLONG_MAX;

  static int64 div(int64 a, int64 b) {
    return a / b - ((a ^ b) < 0 and a % b);
  }

  bool isect(iterator x, iterator y) const {
    if (y == end()) {
      x->p = kInfinity;
      return false;
    } else if (x->m == y->m) {
      x->p = x->c > y->c ? kInfinity : -kInfinity;
    } else {
      x->p = div(y->c - x->c, x->m - y->m);
    }
    return x->p >= y->p;
  }

public:
  void add(int64 m, int64 c) {
    auto z = insert({m, c, 0});
    auto y = z++;
    auto x = y;
    while (isect(y, z)) {
      z = erase(z);
    }
    if (x != begin() and isect(--x, y)) {
      isect(x, y = erase(y));
    }
    while ((y = x) != begin() and (--x)->p >= y->p) {
      isect(x, erase(y));
    }
  }

  [[nodiscard]] int64 query(int64 x) const {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.m * x + l.c;
  }
};

void dijkstra(const vector<vector<pair<int, int64>>> &g, vector<int64> &d) {
  const int n = (int) g.size();

  vector<int> p(n, -1);
  min_heap<pair<int64, int>> q;

  for (int x = 0; x < n; x++) {
    q.emplace(d[x], x);
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
}

inline void solution() {
  const int n = Read::Int();
  const int m = Read::Int();
  const int k = Read::Int();

  vector<vector<pair<int, int64>>> g(n);
  for (int i = 0; i < m; i++) {
    const int x = Read::Int() - 1;
    const int y = Read::Int() - 1;
    const int w = Read::Int();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  vector<vector<int64>> dp(k + 1, vector<int64>(n, kInf64));

  dp[0][0] = 0;
  dijkstra(g, dp[0]);

  LineContainer cht;
  auto update_cht = [&cht](const vector<int64> &dp) {
    cht.clear();
    const int n = dp.size();
    for (int x = 0; x < n; x++) {
      cht.add(2 * (x + 1), -(dp[x] + (x + 1) * 1LL * (x + 1)));
    }
  };

  for (int i = 1; i <= k; i++) {
    update_cht(dp[i - 1]);
    for (int x = 0; x < n; x++) {
      dp[i][x] = -cht.query(x + 1) + (x + 1) * 1LL * (x + 1);
    }
    dijkstra(g, dp[i]);
  }

  for (const int64 ans : dp[k]) {
    cout << ans << ' ';
  }
  cout << '\n';
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