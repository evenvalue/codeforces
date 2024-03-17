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

namespace Read {
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
}//namespace Read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

class dsu {
  int n;
  std::vector<int> e;

  int pfind(const int x) {
    return (e[x] < 0 ? x : e[x] = pfind(e[x]));
  }

public:
  dsu() : n(0), comp(0) {}
  explicit dsu(const int n) : n(n), comp(n), e(n, -1) {}

  int comp;

  int find(const int x) {
    assert(0 <= x and x < n);
    return pfind(x);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    comp--;
    return true;
  }

  bool same(const int x, const int y) {
    return (find(x) == find(y));
  }

  int size(const int x) {
    return -e[find(x)];
  }

  std::vector<std::vector<int>> components() {
    std::vector<std::vector<int>> res(n);
    for (int x = 0; x < n; x++) {
      res[pfind(x)].push_back(x);
    }
    res.erase(
        std::remove_if(res.begin(), res.end(), [&](const std::vector<int> &v) { return v.empty(); }),
        res.end());
    return res;
  }
};

struct Consecutive {
  int x;
  int y;
};

void reject() {
  cout << 0 << '\n';
  exit(0);
}

vector<int> topsort(const vector<vector<int>> &g) {
  const int n = g.size();
  vector<bool> visit(n);
  vector<bool> enter(n);

  function<bool(int)> find_cycle = [&](const int x) {
    visit[x] = enter[x] = true;
    bool found_cycle = false;
    for (const int y : g[x]) {
      if (enter[y]) found_cycle = true;
      if (visit[y]) continue;
      found_cycle |= find_cycle(y);
    }
    enter[x] = false;
    return found_cycle;
  };

  for (int x = 0; x < n; x++) {
    if (not visit[x] and find_cycle(x)) reject();
  }

  vector<int> order;
  function<void(int)> dfs = [&](const int x) {
    visit[x] = true;
    for (const int y : g[x]) {
      if (visit[y]) continue;
      dfs(y);
    }
    order.push_back(x);
  };

  fill(visit.begin(), visit.end(), false);
  for (int x = 0; x < n; x++) {
    if (not visit[x]) dfs(x);
  }

  return order;
}

inline void solution() {
  const int n = Read::Int();
  const int k = Read::Int();

  vector<vector<int>> dag(n);
  for (int x = 0; x < n; x++) {
    const int p = Read::Int() - 1;
    if (p != -1) dag[x].push_back(p);
  }

  vector<Consecutive> cc(k);
  dsu d(n);

  for (auto &[x, y] : cc) {
    x = Read::Int() - 1;
    y = Read::Int() - 1;
    d.unite(x, y);
  }

  vector<vector<int>> g(n);
  for (int x = 0; x < n; x++) {
    for (const int y : dag[x]) {
      if (d.same(x, y)) continue;
      g[d.find(x)].push_back(d.find(y));
    }
  }

  for (const auto &[x, y] : cc) {
    dag[y].push_back(x);
  }

  const vector<int> order = topsort(dag);
  vector<int> templated = topsort(g);

  vector<vector<int>> comp(n);
  for (int x = 0; x < n; x++) {
    comp[d.find(x)].push_back(x);
  }

  vector<int> idx(n);
  for (int i = 0; i < n; i++) {
    idx[order[i]] = i;
  }

  for (auto &c : comp) {
    sort(c.begin(), c.end(), [&](const int x, const int y) {
      return idx[x] < idx[y];
    });
  }

  vector<int> ans;
  for (const int x : templated) {
    if (d.find(x) != x) continue;
    ans.insert(ans.end(), comp[x].begin(), comp[x].end());
  }

  for (const int x : ans) {
    cout << x + 1 << ' ';
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