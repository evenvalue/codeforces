#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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
constexpr int64 kInf64 = 1e16 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

class SegTree {
  const int n;
  vector<int> par;
  vector<int> pos;

  void build(const int x, const int l, const int r) {
    if (l == r) {
      pos[l] = x;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    par[x + 1] = par[y] = x;
    build(x + 1, l, mid);
    build(y, mid + 1, r);
  }

  void get_nodes(const int x, const int l, const int r, const int ql, const int qr, vector<int> &nodes) const {
    if (ql <= l and r <= qr) {
      nodes.push_back(x);
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (ql <= mid) {
      get_nodes(x + 1, l, mid, ql, qr, nodes);
    }
    if (mid < qr) {
      get_nodes(y, mid + 1, r, ql, qr, nodes);
    }
  }

public:
  explicit SegTree(const int n) : n(n), pos(n), par(2 * n - 1) {
    build(0, 0, n - 1);
  }

  int operator[](const int x) const {
    return pos[x];
  }

  [[nodiscard]] int parent(const int x) const {
    return par[x];
  }

  [[nodiscard]] vector<int> range(const int l, const int r) const {
    vector<int> v;
    get_nodes(0, 0, n - 1, l, r, v);
    return v;
  }

  [[nodiscard]] int size() const {
    return 2 * n - 1;
  }
};

pair<vector<int64>, vector<int>> dijkstra(const vector<vector<pair<int, int>>> &g, const int s) {
  const int n = (int) g.size();

  vector<int64> d(n, kInf64);
  vector<int> p(n, -1);
  min_heap<pair<int64, int>> q;

  d[s] = 0;
  q.push({0, s});

  while (not q.empty()) {
    const auto [dist, x] = q.top();
    q.pop();
    if (d[x] < dist) continue;
    for (const auto &[y, w] : g[x]) {

      if (d[y] <= d[x] + w) continue;
      d[y] = d[x] + w;
      p[y] = x;
      q.push({d[y], y});
    }
  }

  return make_pair(d, p);
}

inline void solution() {
  const int n = read::Int();
  const int q = read::Int();
  const int s = read::Int() - 1;

  auto first = [&](const int x) {
    return n + x;
  };

  auto second = [&](const int x) {
    return 3 * n + x;
  };

  vector<vector<pair<int, int>>> g(5 * n);

  SegTree st(n);
  for (int x = 1; x < st.size(); x++) {
    g[first(st.parent(x))].emplace_back(first(x), 0);
    g[second(x)].emplace_back(second(st.parent(x)), 0);
  }

  for (int x = 0; x < n; x++) {
    g[first(st[x])].emplace_back(x, 0);
    g[x].emplace_back(second(st[x]), 0);
  }

  for (int i = 0; i < q; i++) {
    const int type = read::Int();
    if (type == 1) {
      const int x = read::Int() - 1;
      const int y = read::Int() - 1;
      const int w = read::Int();
      g[x].emplace_back(y, w);
    } else {
      const int x = read::Int() - 1;
      const int l = read::Int() - 1;
      const int r = read::Int() - 1;
      const int w = read::Int();

      const vector<int> &range = st.range(l, r);
      for (const int y : range) {
        type == 2 ? g[x].emplace_back(first(y), w)
                  : g[second(y)].emplace_back(x, w);
      }
    }
  }

  const vector<int64> dist = dijkstra(g, s).first;
  for (int x = 0; x < n; x++) {
    cout << (dist[x] >= kInf64 ? -1 : dist[x]) << ' ';
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
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}