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

template<typename T>
class FenwickTree {
  size_t n;
  vector<T> bit;

public:
  explicit FenwickTree(const size_t N) : n(N), bit(N, T{}) {}
  explicit FenwickTree(const vector<T> &a) : FenwickTree(a.size()) {
    n = a.size();
    for (int i = 0; i < n; i++) {
      update(i, a[i]);
    }
  }

  [[nodiscard]] T query(int r) const {
    T ans{};
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
      ans += bit[i];
    }
    return ans;
  }

  [[nodiscard]] T query(const int l, const int r) const {
    return query(r) - query(l - 1);
  }

  void update(const int i, const T delta) {
    for (int j = i; j < n; j |= j + 1) {
      bit[j] += delta;
    }
  }
};

inline void solution() {
  const int n = read::Int();
  const int kMaxDist = read::Int();
  const int kMaxWeight = read::Int();

  vector<vector<pair<int, int>>> g(n);
  for (int x = 1; x < n; x++) {
    const int y = read::Int() - 1;
    const int w = read::Int();
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  }

  vector<int> sz(n);
  vector<bool> decomposed(n);

  function<int(int, int)> subtree_size = [&](const int x, const int p) {
    sz[x] = 1;
    for (const auto [y, w] : g[x]) {
      if (decomposed[y] or y == p) continue;
      sz[x] += subtree_size(y, x);
    }
    return sz[x];
  };

  function<int(int, int, int)> centroid = [&](const int x, const int p, const int size) {
    int c = x;
    for (const auto [y, w] : g[x]) {
      if (decomposed[y] or y == p) continue;
      if (2 * sz[y] < size) continue;
      c = centroid(y, x, size);
      break;
    }
    return c;
  };

  struct Property {
    int depth;
    int64 weight;
  };

  auto count_pairs = [&](const int root, const int kDist, const int kWeight) -> int64 {
    vector<Property> nodes;
    function<int(int, int, int, int64)> dfs = [&](const int x, const int p, const int d, const int64 cost) {
      int sz = 1;
      nodes.push_back({d, cost});
      for (const auto [y, w] : g[x]) {
        if (y == p or decomposed[y]) continue;
        sz += dfs(y, x, d + 1, cost + w);
      }
      return sz;
    };

    const int m = dfs(root, -1, 0, 0);
    sort(nodes.begin(), nodes.end(), [](const Property &x, const Property &y) {
      return x.weight < y.weight;
    });

    FenwickTree<int64> dist(m + 1);

    int64 pairs = 0;
    for (int i = m - 1, j = 0; i >= 0; i--) {
      while (j < m and nodes[i].weight + nodes[j].weight <= kWeight) {
        dist.update(nodes[j].depth, 1);
        j++;
      }
      pairs += dist.query(min(m, kDist - nodes[i].depth));
      if (2 * nodes[i].weight <= kWeight and 2 * nodes[i].depth <= kDist) {
        pairs--;
      }
    }

    return pairs;
  };

  int64 ans = 0;

  function<void(int)> decompose = [&](int x) {
    x = centroid(x, -1, subtree_size(x, -1));
    decomposed[x] = true;

    ans += count_pairs(x, kMaxDist, kMaxWeight);

    for (const auto [y, w] : g[x]) {
      if (decomposed[y]) continue;
      ans -= count_pairs(y, kMaxDist - 2, kMaxWeight - 2 * w);
    }

    for (const auto [y, w] : g[x]) {
      if (decomposed[y]) continue;
      decompose(y);
    }
  };

  decompose(0);
  cout << ans / 2 << '\n';
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