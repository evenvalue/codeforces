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
constexpr int64 kInf64 = 1e18 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = Read::Int();
  const int k = Read::Int();

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = Read::Int() - 1;
    const int y = Read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> p(n, -1);
  vector<pair<int, int>> depth(n);

  function<void(int)> dfs = [&](const int x) {
    depth[x].second = x;
    for (const int y : g[x]) {
      if (y == p[x]) continue;
      p[y] = x;
      depth[y].first = depth[x].first + 1;
      dfs(y);
    }
  };

  dfs(0);
  sort(depth.rbegin(), depth.rend());

  vector<bool> marked(n);
  vector<pair<int, int>> contrib;

  for (const auto [d, x] : depth) {
    contrib.emplace_back(0, x);
    int y = x;
    while (y != -1 and not marked[y]) {
      marked[y] = true;
      contrib.back().first++;
      y = p[y];
    }
  }

  sort(contrib.rbegin(), contrib.rend());

  int64 ans = -kInf64;
  for (int reds = 1, non_blue = 0; reds <= k; reds++) {
    non_blue += contrib[reds - 1].first;
    const int blue = min(n / 2, n - non_blue);
    const int64 part1 = (n - reds) * 1LL * reds;
    const int64 part2 = (n - blue) * 1LL * blue;
    ans = max(ans, part1 - part2);
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