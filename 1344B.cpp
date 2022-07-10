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

int check(const vector<string> &a) {
  const int n = (int) a.size() - 2, m = (int) a[0].size() - 2;
  vector<vector<int>> whites(n + 2, vector<int>(m + 2));
  int cnt = 0;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= m; c++) {
      whites[r][c] = whites[r][c - 1] + (a[r][c] == '.');
    }
    if (whites[r][m] == m) cnt++;
  }
  for (int r = 1; r <= n; r++) {
    int b1 = 0, b2 = 0;
    for (int c = 1; c <= m; c++) {
      if (a[r][c] == '.') continue;
      b1 = c;
      break;
    }
    for (int c = m; c >= 1; c--) {
      if (a[r][c] == '.') continue;
      b2 = c;
      break;
    }
    if (whites[r][b2] - whites[r][b1] > 0) return -1;
  }
  return cnt;
}

vector<string> transpose(const vector<string> &a) {
  const int m = (int) a.size(), n = (int) a[0].size();
  vector<string> b(n, string(m, '-'));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      b[r][c] = a[c][r];
    }
  }
  return b;
}

inline void solution() {
  const int n = read::Int(), m = read::Int();
  vector<string> a(n + 2);
  a[0] = a[n + 1] = string(m + 2, '.');
  for (int r = 1; r <= n; r++) {
    a[r] = '.' + read::String() + '.';
  }
  const int c1 = check(a), c2 = check(transpose(a));
  if (min(c1, c2) == -1 or (min(c1, c2) == 0 and max(c1, c2) > 0)) {
    cout << -1 << '\n';
    return;
  }

  vector<vector<bool>> visit(n + 2, vector<bool>(m + 2));
  for (int r = 0; r < visit.size(); r++) {
    for (int c = 0; c < visit[0].size(); c++) {
      visit[r][c] = (a[r][c] == '.');
    }
  }

  vector<pair<int, int>> neighbours = {
      {1, 0},
      {0, 1},
      {-1, 0},
      {0, -1}};

  function<void(int, int)> dfs = [&](const int r, const int c) {
    if (visit[r][c]) return;
    visit[r][c] = true;
    for (const auto [dr, dc] : neighbours) {
      dfs(r + dr, c + dc);
    }
  };

  int comps = 0;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= m; c++) {
      if (visit[r][c]) continue;
      dfs(r, c);
      comps++;
    }
  }
  cout << comps << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}