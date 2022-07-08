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

int remove_min_factor(int &x, const vector<int> &min_fact) {
  const int p = min_fact[x];
  while (x % p == 0) {
    x /= p;
  }
  return p;
}

inline void solution(const vector<int> &min_fact) {
  const int n = read::Int();
  vector<int> a = read::Vec<int>(n);
  vector<pair<int, int>> ans(n, {1, 1});
  for (int i = 0; i < n; i++) {
    ans[i].first = remove_min_factor(a[i], min_fact);
    ans[i].second = a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << (ans[i].second == 1 ? -1 : ans[i].first) << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << (ans[i].second == 1 ? -1 : ans[i].second) << ' ';
  }
  cout << '\n';
}

vector<int> sieve(const int n) {
  vector<int> min_fact(n + 1);
  iota(min_fact.begin(), min_fact.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (min_fact[i] != i) continue;
    for (int64 j = i * 1LL * i; j <= n; j += i) {
      min_fact[j] = min(min_fact[j], i);
    }
  }
  return min_fact;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  const vector<int> min_fact = sieve(1e7 + 5);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution(min_fact);
  }
}