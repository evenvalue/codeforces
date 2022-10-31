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

inline void solution() {
  const int n = read::Int();
  const vector<int> a = read::Vec<int>(n);
  vector<vector<int>> dp(n, vector<int>(5, -1));

  std::fill(dp[0].begin(), dp[0].end(), 0);

  for (int i = 1; i < n; i++) {
    for (int hand = 0; hand < 5; hand++) {
      for (int prev_hand = 0; prev_hand < 5; prev_hand++) {
        if (dp[i - 1][prev_hand] == -1) continue;
        if (a[i - 1] == a[i] and prev_hand == hand) continue;
        if (a[i - 1] < a[i] and prev_hand >= hand) continue;
        if (a[i - 1] > a[i] and prev_hand <= hand) continue;
        dp[i][hand] = prev_hand;
      }
    }
  }

  vector<int> ans;
  for (int last_hand = 0; last_hand < 5; last_hand++) {
    for (int i = n - 1, h = last_hand; i >= 0 and h != -1; h = dp[i][h], i--) {
      ans.push_back(h);
    }
    if (ans.size() == n) {
      reverse(ans.begin(), ans.end());
      for (const int x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
      return;
    }
    ans.clear();
  }
  cout << -1 << '\n';
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