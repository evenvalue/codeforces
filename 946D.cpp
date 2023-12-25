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
  const int k = read::Int();

  vector<string> schedule = read::Vec<string>(n);

  vector<vector<int>> lectures(n);
  for (int day = 0; day < n; day++) {
    for (int i = 0; i < m; i++) {
      if (schedule[day][i] == '0') continue;
      lectures[day].push_back(i);
    }
  }

  vector<vector<int>> attend(n, vector<int>(k + 1, kInf));
  for (int day = 0; day < n; day++) {
    for (int bunk = 0; bunk <= k; bunk++) {
      const int classes = lectures[day].size();
      if (bunk >= classes) {
        attend[day][bunk] = 0;
        continue;
      }
      for (int l = 0; l <= bunk; l++) {
        const int r = bunk - l;
        const int first = lectures[day][l];
        const int last = lectures[day][classes - r - 1];
        attend[day][bunk] = min(attend[day][bunk], last - first + 1);
      }
    }
  }

  vector<int> dp = attend[0];
  for (int day = 1; day < n; day++) {
    vector<int> nxt(k + 1, kInf);
    for (int skips = 0; skips <= k; skips++) {
      for (int bunk = 0; bunk <= skips; bunk++) {
        nxt[skips] = min(nxt[skips], dp[skips - bunk] + attend[day][bunk]);
      }
    }
    dp = nxt;
  }

  cout << dp[k] << '\n';
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