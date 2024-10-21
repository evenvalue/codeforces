#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
T read() {
  T x;
  cin >> x;
  return x;
}

template<typename T1, typename T2>
pair<T1, T2> read_pair() {
  pair<T1, T2> p;
  cin >> p.first;
  cin >> p.second;
  return p;
}

template<typename T>
vector<T> read_vec(const int n, const int index = 0) {
  vector<T> v(n + index);
  for (int i = index; i < n + index; i++) {
    v[i] = read<T>();
  }
  return v;
}

template<typename T>
vector<vector<T>> read_vec_vec(const int n, const int m, const int index_n = 0, const int index_m = 0) {
  vector<vector<T>> grid(n + index_n);
  for (int i = index_n; i < n + index_n; i++) {
    grid[i] = read_vec<T>(m, index_m);
  }
  return grid;
}

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e17 + 10;
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

inline void solution() {
  const int n = read<int>();
  auto a = read_vec<int>(n);
  auto b = read_vec<int>(n);

  vector<vector<pair<int, int64>>> g(n);
  for (int i = 0; i < n; i++) {
    g[i].emplace_back(b[i] - 1, a[i]);
    if (i != 0) g[i].emplace_back(i - 1, 0);
  }

  auto d = dijkstra(g, {0}).first;

  vector<int64> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  int64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, pref[i] - d[i]);
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
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}