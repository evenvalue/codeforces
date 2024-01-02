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

struct edge {
  int x;
  int y;
};

inline void solution() {
  const int n = read::Int();

  vector<set<int>> g(n);

  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].insert(y);
    g[y].insert(x);
  }

  vector<edge> del;
  auto delete_edge = [&](const int x, const int y) {
    g[x].erase(y);
    g[y].erase(x);
    del.push_back({x, y});
  };

  vector<set<int>> rem(n);

  function<void(int, int)> dfs = [&](const int x, const int p) {
    const int tmp = x;

    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x);
    }

    for (const int y : rem[x]) {
      g[x].erase(y);
    }

    const int children = g[x].size() - (p != -1);
    if (children >= 2) {
      if (p != -1) {
        g[x].erase(p);
        rem[p].insert(x);
        del.push_back({x, p});
      }
      while (g[x].size() > 2) {
        delete_edge(*g[x].begin(), x);
      }
    }
  };

  dfs(0, -1);

  vector<int> comp(n, -1);
  function<void(int, int)> mark = [&](const int x, int id) {
    comp[x] = id;
    for (const int y : g[x]) {
      if (comp[y] != -1) continue;
      mark(y, id);
    }
  };

  int id = 0;
  for (int x = 0; x < n; x++) {
    if (comp[x] == -1) mark(x, id++);
  }

  vector<vector<int>> ends(id);
  for (int x = 0; x < n; x++) {
    if (g[x].size() == 1) {
      ends[comp[x]].push_back(x);
    } else if (g[x].empty()) {
      ends[comp[x]] = {x, x};
    }
  }

  vector<edge> add;
  for (int i = 1; i < id; i++) {
    add.push_back({ends[i - 1][1], ends[i][0]});
  }

  assert(del.size() == add.size());

  cout << add.size() << '\n';
  for (int i = 0; i < add.size(); i++) {
    cout << del[i].x + 1 << ' ' << del[i].y + 1 << ' ';
    cout << add[i].x + 1 << ' ' << add[i].y + 1 << '\n';
  }
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