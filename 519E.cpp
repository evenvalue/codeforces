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

class TreeAnc {
  const int n;
  const vector<vector<int>> g;

  vector<vector<int>> st;
  vector<int> tin;
  vector<int> tout;

  int lg;

  int dfs(const int x, const int p = -1, int time = 0) {
    tin[x] = time++;
    st[x][0] = p;
    subsize[x] = 1;
    for (const int y : g[x]) {
      if (y == p) continue;
      depth[y] = depth[x] + 1;
      time = dfs(y, x, time);
      subsize[x] += subsize[y];
    }
    tout[x] = time++;
    return time;
  }

public:
  vector<int> depth;
  vector<int> subsize;

  explicit TreeAnc(const vector<vector<int>> &g, const int root = 0) : g(g), n(g.size()), tin(n), tout(n), lg(ceil(log2(n))), depth(n), subsize(n) {
    st.assign(n, vector<int>(lg + 1));
    dfs(root);
    for (int j = 1; j <= lg; j++) {
      for (int i = 0; i < n; i++) {
        const int anc = st[i][j - 1];
        st[i][j] = anc == -1 ? -1 : st[anc][j - 1];
      }
    }
  }

  bool is_anc(const int x, const int y) {
    return (tin[x] <= tin[y]) and (tout[x] >= tout[y]);
  }

  int lca(int x, const int y) {
    if (is_anc(x, y)) return x;
    if (is_anc(y, x)) return y;
    for (int j = lg; j >= 0; j--) {
      const int anc = st[x][j];
      if (anc != -1 and not is_anc(anc, y)) {
        x = anc;
      }
    }
    return st[x][0];
  }

  int up(int x, const int dist) {
    for (int j = lg; j >= 0; j--) {
      if (dist & (1 << j)) x = st[x][j];
    }
    return x;
  }
};

inline void solution() {
  const int n = read<int>();
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  TreeAnc tree(g);
  auto &depth = tree.depth;
  auto &subsize = tree.subsize;

  const int m = read<int>();
  for (int i = 0; i < m; i++) {
    int x = read<int>() - 1;
    int y = read<int>() - 1;
    const int l = tree.lca(x, y);
    const int dist = (depth[x] + depth[y]) - 2 * depth[l];
    if (dist % 2) {
      cout << 0 << '\n';
    } else if (x == y) {
      cout << n << '\n';
    } else if (depth[x] == depth[y]) {
      const int px = tree.up(x, depth[x] - depth[l] - 1);
      const int py = tree.up(y, depth[y] - depth[l] - 1);
      cout << n - subsize[px] - subsize[py] << '\n';
    } else {
      if (depth[x] < depth[y]) swap(x, y);
      const int mid = tree.up(x, dist / 2);
      const int px = tree.up(x, dist / 2 - 1);
      cout << subsize[mid] - subsize[px] << '\n';
    }
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