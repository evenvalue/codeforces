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

pair<int, int> ask(const vector<int> &nodes) {
  if (nodes.empty()) return {-1, -1};

  cout << "? " << nodes.size() << '\n';
  for (const int x : nodes) {
    cout << x + 1 << ' ';
  }
  cout << endl;

  const int x = Read::Int() - 1;
  const int d = Read::Int();

  return {x, d};
}

void say(const int x, const int y) {
  cout << "! " << x + 1 << ' ' << y + 1 << endl;
  if (Read::String() != "Correct") exit(0);
}

inline void solution() {
  const int n = Read::Int();
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = Read::Int() - 1;
    const int y = Read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> full_house(n);
  iota(full_house.begin(), full_house.end(), 0);

  const auto [r, dist] = ask(full_house);

  vector<vector<int>> depth(n);
  vector<int> parent(n);

  function<void(int, int, int)> dfs = [&](const int x, const int p, const int deep) {
    parent[x] = p;
    depth[deep].push_back(x);
    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x, deep + 1);
    }
  };
  dfs(r, -1, 0);

  int a = -1;
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    const int mid = (lo + hi + 1) / 2;
    const auto [x, d] = ask(depth[mid]);
    if (d != dist) {
      hi = mid - 1;
    } else {
      a = x;
      lo = mid;
    }
  }

  vector<bool> discovered(n);
  for (int x = a; x != r; x = parent[x]) {
    discovered[x] = true;
  }

  const int remain = dist - lo;

  int del = -1;
  for (const int x : depth[remain]) {
    if (discovered[x]) del = x;
  }

  auto final = depth[remain];
  const auto it = find(final.begin(), final.end(), del);
  if (it != final.end()) final.erase(it);

  const auto [b, d] = ask(final);
  say(a, b);
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