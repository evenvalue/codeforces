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
    return res;
  }
};

struct edge {
  int x;
  int y;
};

inline void solution() {
  const int n = read::Int();
  const int m1 = read::Int();
  const int m2 = read::Int();

  dsu mocha(n);
  dsu diana(n);

  for (int i = 0; i < m1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    mocha.unite(x, y);
  }

  for (int i = 0; i < m2; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    diana.unite(x, y);
  }

  vector<edge> ans;

  auto add_edge = [&](const int x, const int y) {
    mocha.unite(x, y);
    diana.unite(x, y);
    ans.push_back({x, y});
  };

  for (int x = 1; x < n; x++) {
    if (mocha.same(0, x) or diana.same(0, x)) continue;
    add_edge(0, x);
  }

  vector<int> stk1;
  vector<int> stk2;

  for (int x = 1; x < n; x++) {
    if (mocha.same(0, x)) {
      stk1.push_back(x);
    } else {
      stk2.push_back(x);
    }
  }

  while (not stk1.empty() and not stk2.empty()) {
    const int x = stk1.back();
    const int y = stk2.back();
    if (diana.same(0, x)) {
      stk1.pop_back();
    } else if (mocha.same(0, y)) {
      stk2.pop_back();
    } else {
      add_edge(x, y);
      stk1.pop_back();
      stk2.pop_back();
    }
  }

  cout << ans.size() << '\n';
  for (const auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
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