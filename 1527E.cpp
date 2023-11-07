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

struct Window {
  int l = 0;
  int r = 0;
  int cost = 0;
};

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = read::Int();
  }

  vector<int> last_occ(n + 1, -1);
  vector<int> nxt(n + 1, kInf);
  vector<int> prv(n + 1, -kInf);

  for (int i = 1; i <= n; i++) {
    if (last_occ[a[i]] != -1) {
      nxt[last_occ[a[i]]] = i;
      prv[i] = last_occ[a[i]];
    }
    last_occ[a[i]] = i;
  }

  Window window;

  auto shift = [&](const int l, const int r) {
    while (l < window.l) {
      window.l--;
      if (nxt[window.l] <= window.r) {
        window.cost += nxt[window.l] - window.l;
      }
    }
    while (window.r < r) {
      window.r++;
      if (window.l <= prv[window.r]) {
        window.cost += window.r - prv[window.r];
      }
    }
    while (window.l < l) {
      if (nxt[window.l] <= window.r) {
        window.cost -= nxt[window.l] - window.l;
      }
      window.l++;
    }
    while (r < window.r) {
      if (window.l <= prv[window.r]) {
        window.cost -= window.r - prv[window.r];
      }
      window.r--;
    }
  };

  vector<vector<int>> dp(2, vector<int>(n + 1, kInf));

  function<void(int, int, int, int)> dnc = [&](const int l, const int r, const int optl, const int optr) {
    if (r < l) return;
    const int mid = (l + r) / 2;
    pair<int, int> best{kInf, -1};
    for (int i = optl; i <= min(optr, mid); i++) {
      shift(i, mid);
      if (dp[0][i - 1] + window.cost < best.first) {
        best = {dp[0][i - 1] + window.cost, i};
      }
    }
    dp[1][mid] = best.first;
    const int opt = best.second;
    dnc(l, mid - 1, optl, opt);
    dnc(mid + 1, r, opt, optr);
  };

  dp[0][0] = 0;
  for (int seg = 1; seg <= k; seg++) {
    dnc(seg, n, seg - 1, n);
    swap(dp[0], dp[1]);
  }

  cout << dp[0][n] << '\n';
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