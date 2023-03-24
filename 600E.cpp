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
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read::Int();
  const vector<int> col = read::Vec<int>(n);

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<pair<int, int64>> ans(n);
  vector<map<int, int>> freq(n);

  for (int x = 0; x < n; x++) {
    ans[x] = {1, col[x]};
  }

  auto update_ans = [&](pair<int, int64> &cur, const int c, const int freq) {
    if (freq < cur.first) return;
    if (freq == cur.first) {
      cur.second += c;
    } else {
      cur.first = freq;
      cur.second = c;
    }
  };

  function<void(int, int)> dfs = [&](const int x, const int p) {
    map<int, int> &mine = freq[x];
    mine[col[x]] = 1;

    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x);
      map<int, int> &child = freq[y];
      if (child.size() > mine.size()) {
        swap(mine, child);
        ans[x] = ans[y];
      }
      for (const auto [c, f] : child) {
        mine[c] += f;
        update_ans(ans[x], c, mine[c]);
      }
    }
  };

  dfs(0, -1);
  for (int x = 0; x < n; x++) {
    cout << ans[x].second << ' ';
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