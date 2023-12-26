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
constexpr int kMaxA = 205;

inline void solution() {
  const int n = read::Int();

  vector<int> a = read::Vec<int>(n);
  a.insert(a.begin(), 0);

  vector<vector<int>> freq(kMaxA);
  vector<vector<int>> pref(kMaxA, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int x = 1; x < kMaxA; x++) {
      pref[x][i] = pref[x][i - 1] + (a[i] == x);
    }
    freq[a[i]].push_back(i);
  }

  int ans = 0;
  for (int x = 1; x < kMaxA; x++) {
    const int m = freq[x].size();
    ans = max(ans, m);
    for (int pick = 1; pick < m; pick++) {
      const int l = freq[x][pick - 1] + 1;
      const int r = freq[x][m - pick] - 1;
      if (l > r) break;
      for (int y = 1; y < kMaxA; y++) {
        ans = max(ans, 2 * pick + pref[y][r] - pref[y][l - 1]);
      }
    }
  }

  cout << ans << '\n';
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