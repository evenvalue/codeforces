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
constexpr int kBits = 30;

class Trie {
  vector<array<int, 2>> t;
  vector<int> leaves;

  int add_node() {
    t.push_back({-1, -1});
    leaves.push_back(0);
    return t.size() - 1;
  }

  int ideal = 0;
  int dfs(const int x, const int bit) {
    if (bit == -1) return 0;
    const int child = 1 - ((ideal >> bit) & 1);
    const int y = (t[x][child] == -1 or leaves[t[x][child]] == 0 ? 1 - child : child);
    return dfs(t[x][y], bit - 1) + (y << bit);
  }

public:
  Trie() {
    add_node();
  }

  void add(int x) {
    int cur = 0;
    for (int bit = kBits; bit >= 0; bit--) {
      leaves[cur]++;
      const int child = ((x >> bit) & 1);
      if (t[cur][child] == -1) t[cur][child] = add_node();
      cur = t[cur][child];
    }
    leaves[cur]++;
  }

  void update_node(const int x, const int delta) {
    int cur = 0;
    for (int bit = kBits; bit >= 0; bit--) {
      leaves[cur] += delta;
      const int child = ((x >> bit) & 1);
      cur = t[cur][child];
    }
    leaves[cur] += delta;
  }

  int query(const int x) {
    if (leaves[0] == 0) return -kInf;
    ideal = x;
    return dfs(0, kBits) ^ x;
  }
};

inline void solution() {
  const int n = read<int>();
  int q = read<int>();

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    const int w = read<int>();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  vector<int> cost(n);
  vector<int> depth(n);

  function<void(int, int)> dfs = [&](const int x, const int p) {
    for (const auto [y, w] : g[x]) {
      if (y == p) continue;
      depth[y] = depth[x] + 1;
      cost[y] = cost[x] ^ w;
      dfs(y, x);
    }
  };

  dfs(0, -1);

  array<Trie, 2> trie;
  for (int x = 0; x < n; x++) {
    trie[depth[x] & 1].add(cost[x]);
  }

  int xor_odd = 0;
  while (q--) {
    const char type = read<char>();
    if (type == '^') {
      xor_odd ^= read<int>();
    } else {
      const int x = read<int>() - 1;
      const int w = read<int>();
      const int bit = (depth[x] & 1);

      trie[bit].update_node(cost[x], -1);
      const int op1 = trie[bit].query(w ^ cost[x]);
      trie[bit].update_node(cost[x], 1);

      const int op2 = trie[1 - bit].query(w ^ cost[x] ^ xor_odd);

      cout << max(op1, op2) << ' ';
    }
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
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}