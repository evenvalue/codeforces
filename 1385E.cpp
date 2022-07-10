#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

pair<bool, vector<int>> topological_sort(const vector<vector<int>> &g) {
  const int n = g.size();
  vector<bool> visit(n), enter(n);
  vector<int> topsort;
  function<bool(int)> dfs = [&](const int x) {
    visit[x] = enter[x] = true;
    for (const int y : g[x]) {
      if (enter[y] or (not visit[y] and not dfs(y))) return false;
    }
    topsort.push_back(x);
    enter[x] = false;
    return true;
  };
  for (int x = 0; x < n; x++) {
    if (visit[x]) continue;
    if (not dfs(x)) return {false, {}};
  }
  reverse(topsort.begin(), topsort.end());
  return {true, topsort};
}

inline void solution() {
  const int n = read::Int(), m = read::Int();
  vector<vector<int>> directed(n), undirected(n);
  for (int i = 0; i < m; i++) {
    const int t = read::Int(), x = read::Int() - 1, y = read::Int() - 1;
    auto &g = (t ? directed : undirected);
    g[x].push_back(y);
  }
  const auto [yes, topsort] = topological_sort(directed);
  if (not yes) {
    cout << "NO\n";
    return;
  }
  const vector<int> index = [&, topsort = topsort]() -> vector<int> {
    vector<int> index;
    for (int i = 0; i < n; i++) {
      index[topsort[i]] = i;
    }
    return index;
  }();
  cout << "YES\n";
  for (int x = 0; x < n; x++) {
    for (const int y : directed[x]) {
      cout << x + 1 << ' ' << y + 1 << '\n';
    }
    for (const int y : undirected[x]) {
      const auto [a, b] = (index[x] < index[y] ? make_pair(x, y) : make_pair(y, x));
      cout << a + 1 << ' ' << b + 1 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}