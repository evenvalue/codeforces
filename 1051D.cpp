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
constexpr int kMod = 998244353;

class dsu {
  int n;
  std::vector<int> e;

  int pfind(const int x) {
    return (e[x] < 0 ? x : pfind(e[x]));
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

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  vector<string> bin = {
      "00",
      "01",
      "10",
      "11"};

  vector<vector<int>> new_comp(4, vector<int>(4));
  for (int c1 = 0; c1 < 4; c1++) {
    for (int c2 = 0; c2 < 4; c2++) {
      string prev = bin[c1];
      string cur = bin[c2];

      dsu d(4);
      if (prev[0] == prev[1]) d.unite(0, 1);
      if (prev[0] == cur[0]) d.unite(0, 2);
      if (prev[1] == cur[1]) d.unite(1, 3);
      if (cur[0] == cur[1]) d.unite(2, 3);

      new_comp[c1][c2] = d.comp - (d.same(0, 1) ? 1 : 2);
    }
  }

  vector<vector<vector<int64>>> dp(n + 1, vector<vector<int64>>(k + 2, vector<int64>(4)));

  dp[1][1] = {
      1,
      0,
      0,
      1};

  dp[1][2] = {
      0,
      1,
      1,
      0};

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int prev = 0; prev < 4; prev++) {
        for (int cur = 0; cur < 4; cur++) {
          if (j < new_comp[prev][cur]) continue;
          dp[i][j][cur] += dp[i - 1][j - new_comp[prev][cur]][prev];
          dp[i][j][cur] -= (dp[i][j][cur] >= kMod ? kMod : 0);
        }
      }
    }
  }

  cout << accumulate(dp[n][k].begin(), dp[n][k].end(), 0LL) % kMod << '\n';
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