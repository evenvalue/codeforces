#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using int64 = int64_t;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

int readInt() {
  int x;
  cin >> x;
  return x;
}
int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
char readChar() {
  char c;
  cin >> c;
  return c;
}
string readString() {
  string s;
  cin >> s;
  return s;
}
double readDouble() {
  return stod(readString());
}
ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

void solution() {
  const int n = readInt(), k = readInt();
  vector<int64> a = readVec<int64>(n);
  a.push_back(18);
  for (int64 &x : a)
    x = (int64)pow(10, x);

  int64 ans = 0;
  for (int64 remain = k + 1, i = 0; i < n; i++) {
    const int64 inc = min(remain, (a[i + 1] / a[i]) - 1);
    ans += inc * a[i];
    remain -= inc;
  }
  cout << ans << '\n';
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