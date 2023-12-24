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

template<typename T>
using vec2d = vector<vector<T>>;

template<typename T>
using vec3d = vector<vec2d<T>>;

inline void solution() {
  string s = " " + read::String();
  const int k = read::Int();

  const int n = s.size() - 1;
  const int kMaxDist = 2 * n + 5;

  vec3d<bool> dp1(kMaxDist, vec2d<bool>(k + 1, vector<bool>(2)));
  vec3d<bool> dp2(kMaxDist, vec2d<bool>(k + 1, vector<bool>(2)));

  dp1[n + 2][0][1] = true;

  for (int i = 1; i <= n; i++) {
    for (int x = 1; x < kMaxDist - 1; x++) {
      //case 1: I don't change the thing at pos i
      for (int moves = 0; moves <= k; moves++) {
        for (const int dir : {0, 1}) {
          const int go = (dir == 0 ? -1 : 1);
          if (s[i] == 'F') {
            dp2[x][moves][dir] = dp2[x][moves][dir] or dp1[x - go][moves][dir];
          } else {
            dp2[x][moves][dir] = dp2[x][moves][dir] or dp1[x][moves][1 - dir];
          }
        }
      }
      //case 2: I change the thing at pos i
      for (int moves = 1; moves <= k; moves++) {
        for (const int dir : {0, 1}) {
          const int go = (dir == 0 ? -1 : 1);
          if (s[i] == 'T') {
            dp2[x][moves][dir] = dp2[x][moves][dir] or dp1[x - go][moves - 1][dir];
          } else {
            dp2[x][moves][dir] = dp2[x][moves][dir] or dp1[x][moves - 1][1 - dir];
          }
        }
      }
    }
    swap(dp1, dp2);

    for (auto &v1 : dp2) {
      for (auto &v2 : v1) {
        fill(v2.begin(), v2.end(), false);
      }
    }
  }

  int dist = 0;
  for (int moves = k % 2; moves <= k; moves += 2) {
    for (int x = 0; x < kMaxDist; x++) {
      if (dp1[x][moves][0] or dp1[x][moves][1]) {
        dist = max(dist, abs(x - (n + 2)));
      }
    }
  }

  cout << dist << '\n';
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