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

inline void solution(vector<int> &ans) {
  const int n = read<int>();
  const int m = read<int>();
  const int k = read<int>();
  const int q = read<int>();

  vector<vector<pair<int, int>>> g(n + m);
  for (int i = 0; i < k; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1 + n;
    const int w = read<int>();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  vector<bool> visit(n + m);
  vector<int> p(n + m);

  bool possible = true;
  function<void(int)> dfs = [&](const int x) {
    visit[x] = true;
    for (const auto [y, w] : g[x]) {
      if (visit[y]) {
        possible &= ((p[x] ^ p[y] ^ w) == 0);
      } else {
        p[y] = p[x] ^ w;
        dfs(y);
      }
    }
  };

  int comp = 0;
  for (int x = 0; x < n + m; x++) {
    if (visit[x]) continue;
    dfs(x);
    comp++;
  }

  cout << (possible ? ans[comp - 1] : 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  vector<int> ans(kMaxN);
  ans[0] = 1;
  for (int i = 1; i < kMaxN; i++) {
    ans[i] = (ans[i - 1] * (1LL << 30)) % kMod;
  }

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution(ans);
  }
}