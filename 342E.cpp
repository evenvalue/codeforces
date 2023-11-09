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

namespace read {
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
}//namespace read

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
    for (const int y : g[x]) {
      if (y == p) continue;
      time = dfs(y, x, time);
    }
    tout[x] = time++;
    return time;
  }

public:
  explicit TreeAnc(const vector<vector<int>> &g, const int root = 0) : g(g), n(g.size()), tin(n), tout(n), lg(ceil(log2(n))) {
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
};

class CentroidDecomposition {
  const int n;
  vector<vector<int>> g;

  vector<int> parent;
  vector<int> sz;
  vector<bool> decomposed;

  int subtree_size(const int x, const int p) {
    sz[x] = 1;
    for (const int y : g[x]) {
      if (decomposed[y] or y == p) continue;
      sz[x] += subtree_size(y, x);
    }
    return sz[x];
  }

  int centroid(const int x, const int p, const int size) {
    int c = x;
    for (const int y : g[x]) {
      if (decomposed[y] or y == p) continue;
      if (2 * sz[y] < size) continue;
      c = centroid(y, x, size);
      break;
    }
    return c;
  }

  void decompose(int x, const int p) {
    subtree_size(x, p);
    x = centroid(x, p, sz[x]);
    parent[x] = p;
    decomposed[x] = true;
    for (const int y : g[x]) {
      if (decomposed[y]) continue;
      decompose(y, x);
    }
  }

public:
  explicit CentroidDecomposition(const vector<vector<int>> &t) : n(t.size()), g(t) {
    parent.assign(n, -2);
    decomposed.assign(n, false);
    sz.assign(n, 0);
    decompose(0, -1);
  }

  int operator[](const int x) {
    return parent[x];
  }
};

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  vector<vector<int>> g(n);

  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> depth(n);
  function<void(int, int, int)> dfs = [&](const int x, const int p, const int d) {
    depth[x] = d;
    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x, d + 1);
    }
  };

  dfs(0, -1, 0);

  CentroidDecomposition cd(g);
  TreeAnc tree(g);

  auto dist = [&](const int x, const int y) {
    const int l = tree.lca(x, y);
    return depth[x] + depth[y] - 2 * depth[l];
  };

  vector<int> subtree(n, kInf);

  auto paint = [&](const int x) {
    for (int y = x; y != -1; y = cd[y]) {
      subtree[y] = min(subtree[y], dist(x, y));
    }
  };

  auto nearest = [&](const int x) {
    int ans = kInf;
    for (int y = x; y != -1; y = cd[y]) {
      ans = min(ans, subtree[y] + dist(x, y));
    }
    return ans;
  };

  paint(0);
  for (int query = 0; query < m; query++) {
    const int t = read::Int();
    const int x = read::Int() - 1;
    if (t == 1) {
      paint(x);
    } else {
      cout << nearest(x) << '\n';
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