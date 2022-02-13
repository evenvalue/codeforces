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
  struct edge {
    int x, y;
  };

  const int n = readInt(), m = readInt();
  vector<vector<int>> g(n);
  vector<edge> edges(m);
  for (auto &[x, y] : edges) {
    x = readInt() - 1, y = readInt() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> colour(n, -1);

  function<bool(int, int)> is_bipartite = [&](const int x, const int c) {
    colour[x] = c;
    for (const int y : g[x]) {
      if (colour[y] == colour[x]) return false;
      if (colour[y] != -1) continue;
      if (not is_bipartite(y, 1 - c)) return false;
    }
    return true;
  };

  if (not is_bipartite(0, 0)) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  for (const auto &[x, y] : edges) {
    cout << colour[x];
  }
  cout << '\n';
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