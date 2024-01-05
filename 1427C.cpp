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

struct Celebrity {
  int x;
  int y;
  int t;

  bool operator<(const Celebrity &other) const {
    return t < other.t;
  }
};

int dist(const Celebrity &one, const Celebrity &two) {
  return abs(one.x - two.x) + abs(one.y - two.y);
}

inline void solution() {
  const int r = read::Int();
  const int n = read::Int();

  vector<Celebrity> a(n);
  for (auto &[x, y, t] : a) {
    t = read::Int();
    x = read::Int();
    y = read::Int();
  }

  a.push_back({1, 1, 0});
  sort(a.begin(), a.end());

  vector<int> dp(n + 1, -kInf);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = max(0, i - (5 * r)); j < i; j++) {
      if (dist(a[i], a[j]) > a[i].t - a[j].t) continue;
      dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
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