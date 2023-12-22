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
  int time;

  bool operator<(const edge &other) const {
    return time < other.time;
  }
};

inline void solution() {
  const int n = read::Int();

  vector<edge> edges(n - 1);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);
    edges[i].x = x;
    edges[i].y = y;
  }

  int t = 0;
  function<void(int, int)> dfs = [&](const int x, const int p) {
    for (const auto &[y, i] : g[x]) {
      if (y == p) continue;
      edges[i].time = t++;
      dfs(y, x);
    }
  };

  dfs(0, -1);

  sort(edges.begin(), edges.end());

  vector<int> all_nodes(n);
  iota(all_nodes.begin(), all_nodes.end(), 0);

  auto ask = [&](const vector<int> &nodes) -> int {
    cout << "? " << nodes.size() << ' ';
    for (const int x : nodes) {
      cout << x + 1 << ' ';
    }
    cout << endl;
    return read::Int();
  };

  auto say = [&](const edge &e) {
    cout << "! ";
    cout << e.x + 1 << ' ' << e.y + 1 << endl;
  };

  const int mx = ask(all_nodes);

  auto check = [&](const int cnt) -> bool {
    vector<int> nodes;
    for (int i = 0; i < cnt; i++) {
      nodes.push_back(edges[i].x);
      nodes.push_back(edges[i].y);
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    return (mx == ask(nodes));
  };

  int lo = 1, hi = n - 1;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  say(edges[lo - 1]);
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