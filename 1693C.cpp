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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read<int>();
  const int m = read<int>();

  vector<int> deg(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[y].push_back(x);
    deg[x]++;
  }

  min_heap<pair<int, int>> pq;
  pq.emplace(0, n - 1);

  vector<int> ans(n, kInf);

  while (not pq.empty()) {
    const auto [d, x] = pq.top();
    pq.pop();
    if (ans[x] <= d) continue;
    ans[x] = d;
    for (const int y : g[x]) {
      deg[y]--;
      const int foo = deg[y] + ans[x] + 1;
      pq.emplace(foo, y);
    }
  }

  cout << ans[0] << '\n';
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