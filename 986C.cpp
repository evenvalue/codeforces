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

constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int m = read<int>();
  const int kNodes = (1 << m);

  const int n = read<int>();
  vector<bool> exists(kNodes);
  for (int i = 0; i < n; i++) {
    exists[read<int>()] = true;
  }

  auto node = [&](const int x, const int type) {
    return kNodes * type + x;
  };

  auto complement = [&](const int x) {
    return (1 << m) - 1 - x;
  };

  vector<bool> visit(kNodes * 2);
  function<void(int)> dfs = [&](int x) {
    visit[x] = true;
    if (x < kNodes) {
      const int y = node(complement(x), 1);
      if (visit[y]) return;
      dfs(y);
    } else {
      x -= kNodes;
      for (int bit = 0; bit <= m; bit++) {
        if ((x & (1 << bit)) == 0) continue;
        const int y = node(x - (1 << bit), 1);
        if (not visit[y]) dfs(y);
      }
      if (exists[x] and not visit[x]) dfs(x);
    }
  };

  int ans = 0;
  for (int x = 0; x < kNodes; x++) {
    if (not exists[x]) continue;
    if (visit[node(x, 0)]) continue;
    dfs(node(x, 0));
    ans++;
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