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
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int64> ans(n);
  vector<int> subsize(n, 1);
  function<void(int, int)> dfs1 = [&](const int x, const int p) {
    for (const int y : g[x]) {
      if (y == p) continue;
      dfs1(y, x);
      subsize[x] += subsize[y];
      ans[x] += ans[y];
    }
    ans[x] += subsize[x];
  };

  function<void(int, int)> dfs2 = [&](const int x, const int p) {
    for (const int y : g[x]) {
      if (y == p) continue;
      ans[y] = ans[x] + (n - subsize[y]) - subsize[y];
      dfs2(y, x);
    }
  };

  dfs1(0, -1);
  dfs2(0, -1);

  cout << *max_element(ans.begin(), ans.end()) << '\n';
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