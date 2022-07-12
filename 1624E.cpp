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

int d(const char &c) {
  assert('0' <= c and c <= '9');
  return (c - '0');
}

struct copy_segment {
  int l = -1, r = -1, i = 0;

  friend ostream &operator<<(ostream &output, const copy_segment &segment) {
    output << segment.l << ' ' << segment.r << ' ' << segment.i << '\n';
    return output;
  }
};

inline void solution() {
  const int n = read::Int(), m = read::Int();
  copy_segment seen2d[10][10], seen3d[10][10][10];

  auto last_two = [&](const string &s, const int i) -> copy_segment & {
    return seen2d[d(s[i - 1])][d(s[i])];
  };

  auto last_three = [&](const string &s, const int i) -> copy_segment & {
    return seen3d[d(s[i - 2])][d(s[i - 1])][d(s[i])];
  };

  for (int i = 1; i <= n; i++) {
    const string s = read::String();
    for (int j = 1; j < m; j++) {
      last_two(s, j) = {j, j + 1, i};
    }
    for (int j = 2; j < m; j++) {
      last_three(s, j) = {j - 1, j + 1, i};
    }
  }

  const string s = read::String();

  if (m == 1) {
    cout << -1 << '\n';
    return;
  } else if (m == 2) {
    if (const auto l = last_two(s, 1); l.i) {
      cout << 1 << '\n';
      cout << l;
    } else {
      cout << -1 << '\n';
    }
    return;
  }

  vector<int> dp(m, -kInf);

  dp[1] = (last_two(s, 1).i ? -1 : -kInf);
  dp[2] = (last_three(s, 2).i ? -1 : -kInf);
  for (int i = 3; i < m; i++) {
    last_three(s, i);
    last_two(s, i);
    if (dp[i - 2] != -kInf and last_two(s, i).i > 0) {
      dp[i] = i - 2;
    } else if (dp[i - 3] != -kInf and last_three(s, i).i > 0) {
      dp[i] = i - 3;
    }
  }

  if (dp[m - 1] == -kInf) {
    cout << -1 << '\n';
    return;
  }

  vector<copy_segment> ans;

  for (int i = m - 1; i >= 0; i = dp[i]) {
    ans.push_back(i - dp[i] == 2 ? last_two(s, i) : last_three(s, i));
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (const copy_segment &segment : ans) {
    cout << segment;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}