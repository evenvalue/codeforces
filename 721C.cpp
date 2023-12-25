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

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();
  const int t = read::Int();

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    const int w = read::Int();
    g[x].emplace_back(y, w);
  }

  auto topsort = [&]() {
    vector<int> order;
    vector<bool> visit(n);

    function<void(int)> dfs = [&](const int x) {
      visit[x] = true;
      for (const auto [y, w] : g[x]) {
        if (visit[y]) continue;
        dfs(y);
      }
      order.push_back(x);
    };

    for (int x = 0; x < n; x++) {
      if (not visit[x]) dfs(x);
    }
    return order;
  };


  const vector<int> order = topsort();

  vector<vector<int>> min_time(n, vector<int>(n + 1, kInf));
  vector<vector<int>> parent(n, vector<int>(n + 1, -1));

  min_time[n - 1][1] = 0;

  for (const int x : order) {
    for (int l = 1; l <= n; l++) {
      for (const auto [y, w] : g[x]) {
        if (min_time[x][l] > min_time[y][l - 1] + w) {
          min_time[x][l] = min_time[y][l - 1] + w;
          parent[x][l] = y;
        }
      }
    }
  }

  int length = -1;
  for (int l = n; l >= 0; l--) {
    if (min_time[0][l] <= t) {
      length = l;
      break;
    }
  }

  vector<int> path;
  for (int l = length, x = 0; x != -1; x = parent[x][l], l--) {
    path.push_back(x);
  }

  cout << path.size() << '\n';
  for (const int x : path) {
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