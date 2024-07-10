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
constexpr int kBits = 31;

class Trie {
  vector<int> max_idx;
  vector<array<int, 2>> t;

  int add_node() {
    max_idx.push_back(0);
    t.push_back({-1, -1});
    return t.size() - 1;
  }

  int dfs(const int x, const int bit, const int v, const int lim) {
    if (x == -1) return 0;
    const int nxt = (v >> bit) & 1;
    if (lim & (1 << bit)) {
      const int op1 = (t[x][nxt] == -1 ? 0 : max_idx[t[x][nxt]]);
      const int op2 = dfs(t[x][1 - nxt], bit - 1, v, lim);
      return max(op1, op2);
    } else {
      const int op1 = dfs(t[x][nxt], bit - 1, v, lim);
      return op1;
    }
  }

public:
  Trie() {
    add_node();
  }

  void add(const int x, const int i) {
    int cur = 0;
    max_idx[cur] = i;
    for (int bit = kBits - 1; bit >= 0; bit--) {
      const int nxt = (x >> bit) & 1;
      if (t[cur][nxt] == -1) t[cur][nxt] = add_node();
      cur = t[cur][nxt];
      max_idx[cur] = i;
    }
  }

  int query(const int v, const int lim) {
    return dfs(0, kBits - 1, v, lim);
  }
};

inline void solution() {
  const int n = read<int>();
  const auto k = read<int64>();

  auto a = read_vec<int>(n);
  a.insert(a.begin(), 0);

  vector<int> dp(n + 1);
  auto check = [&](const int lim) -> bool {
    Trie trie;
    trie.add(a[1], 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
      dp[i] = max(dp[i - 1], trie.query(a[i], lim));
      trie.add(a[i], i);
    }
    return (accumulate(dp.begin(), dp.end(), 0LL) >= k);
  };

  int ans = 0;
  int lo = 0, hi = INT_MAX;
  while (lo <= hi) {
    const int mid = (lo + 0LL + hi) / 2;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans - 1 << '\n';
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