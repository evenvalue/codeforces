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

using bit = bitset<20>;

int lowest(const int mask) {
  int x = 0;
  while ((mask & (1 << x)) == 0) {
    x++;
  }
  return x;
}

inline void solution() {
  const int n = Read::Int();
  const int m = Read::Int();

  vector<bit> g(n);
  for (int i = 0; i < m; i++) {
    const int x = Read::Int() - 1;
    const int y = Read::Int() - 1;
    g[x][y] = true;
    g[y][x] = true;
  }

  const int kMaxMask = (1 << n);
  vector<bit> dp(kMaxMask);

  for (int x = 0, i = 1; i < kMaxMask; x++, i <<= 1) {
    dp[i][x] = true;
  }

  for (int mask = 1; mask < (1 << n); mask++) {
    bit nbr;
    for (int x = 0; x < n; x++) {
      if (not dp[mask][x]) continue;
      nbr |= g[x];
    }
    for (int y = lowest(mask) + 1; y < n; y++) {
      if (mask & (1 << y)) continue;
      if (not nbr[y]) continue;
      dp[mask | (1 << y)][y] = true;
    }
  }

  int cycle = -1;

  for (int mask = 1; mask < kMaxMask; mask++) {
    if (__builtin_popcount(mask) <= 1) continue;

    bool forms_cycle = false;
    const int start = lowest(mask);
    for (int x = start + 1; x < n; x++) {
      if (dp[mask][x] and g[x][start]) {
        forms_cycle = true;
        break;
      }
    }

    if (not forms_cycle) continue;

    bit nbr(mask);
    for (int x = 0; x < n; x++) {
      if ((mask & (1 << x)) == 0) continue;

      nbr |= g[x];
    }
    if (nbr == bit(kMaxMask - 1)) {
      cycle = mask;
      break;
    }
  }

  if (cycle == -1) {
    cout << "No\n";
    return;
  }

  vector<int> ans(n);

  for (int mask = cycle, nxt = lowest(mask); mask != 0;) {
    int x = -1;
    for (int i = 0; i < n; i++) {
      if (dp[mask][i] and g[i][nxt]) {
        x = i;
        break;
      }
    }
    ans[x] = nxt;
    nxt = x;
    mask -= (1 << x);
    for (int y = 0; y < n; y++) {
      if (cycle & (1 << y)) continue;
      if (g[x][y]) {
        ans[y] = x;
      }
    }
  }

  cout << "Yes\n";
  for (const int x : ans) {
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