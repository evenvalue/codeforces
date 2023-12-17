#include <bits/stdc++.h>
using namespace std;

#define int long long

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

vector<int> shift(const vector<int> &v) {
  const int n = v.size();
  vector<int> a(n);
  int i = distance(v.begin(), find(v.begin(), v.end(), 0));
  for (int j = i; j < i + n; j++) {
    a[j - i] = v[j % n];
  }
  return a;
}

inline void solution() {
  const int n = read::Int();
  vector<int> a = shift(read::Vec<int>(n));

  int ans = 0;

  vector<pair<int, int>> stk;
  int local_ans = n;
  for (int i = 1; i < n; i++) {
    int freq = 1;
    while (not stk.empty() and stk.back().first > a[i]) {
      const auto [x, f] = stk.back();
      stk.pop_back();
      local_ans -= f * x;
      freq += f;
    }
    stk.emplace_back(a[i], freq);
    local_ans += a[i] * freq;
    ans = max(ans, local_ans);
  }

  local_ans = 0;
  set<int> mex;
  for (int i = 0; i <= n; i++) {
    mex.insert(i);
  }
  for (const int x : a) {
    mex.erase(x);
    local_ans += *mex.begin();
  }

  ans = max(ans, local_ans);

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