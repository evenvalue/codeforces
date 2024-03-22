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


bool assign1(const vector<vector<int>> &g) {
  const int n = g.size();
  if (g[0].size() != n - 1) return false;
  vector<int> ans(n - 1, 1);
  cout << 1 << '\n';
  for (const int x : ans) {
    cout << x << ' ';
  }
  cout << endl;
  return true;
}

bool assign2(const vector<vector<int>> &g) {
  const int n = g.size();
  bitset<2> seen;

  vector<int> c(n);
  function<void(int, int)> dfs = [&](const int x, const int col) {
    if (g[x].size() == 1) {
      seen[col] = true;
    }
    for (const int y : g[x]) {
      c[y] = 1 - col;
      dfs(y, 1 - col);
    }
  };

  for (const int y : g[0]) {
    seen[0] = seen[1] = false;
    c[y] = 0;
    dfs(y, 0);
    if (seen[0] and seen[1]) return false;
    else if (seen[1]) {
      c[y] = 1;
      dfs(y, 1);
    }
  }

  cout << 2 << '\n';
  for (int i = 1; i < n; i++) {
    cout << c[i] + 1 << ' ';
  }
  cout << endl;
  return true;
}

bool assign3(const vector<vector<int>> &g) {
  const int n = g.size();

  vector<int> depth(n);
  function<void(int)> dfs = [&](const int x) {
    for (const int y : g[x]) {
      depth[y] = depth[x] + 1;
      dfs(y);
    }
  };

  dfs(0);

  vector<int> c(n);
  for (int x = 1; x < n; x++) {
    const int foo = (depth[x] % 3 == 0 ? 3 : depth[x] % 3);
    c[x] = foo;
  }

  cout << 3 << '\n';
  for (int x = 1; x < n; x++) {
    cout << c[x] << ' ';
  }
  cout << endl;

  return true;
}

int assign(const vector<vector<int>> &g) {
  if (assign1(g)) return 1;
  if (assign2(g)) return 2;
  if (assign3(g)) return 3;
  assert(false);
}

inline void solution() {
  const int n = Read::Int();
  vector<vector<int>> g(n);
  for (int x = 1; x < n; x++) {
    const int p = Read::Int() - 1;
    g[p].push_back(x);
  }
  const int kColours = assign(g);

  while (true) {
    const int type = Read::Int();
    if (type != 0) break;
    const vector<int> cnt = Read::Vec<int>(kColours);

    vector<pair<int, int>> p;
    for (int c = 0; c < kColours; c++) {
      if (cnt[c] == 0) continue;
      p.emplace_back(cnt[c], c);
    }

    sort(p.begin(), p.end(), [&](const auto p1, const auto p2) {
      if (p1.first != p2.first) {
        return (p1.first < p2.first);
      } else {
        return (((p1.second + 1) % 3) == p2.second);
      }
    });

    cout << p[0].second + 1 << endl;
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