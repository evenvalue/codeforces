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
constexpr int kMaxN = 2e5 + 10;
constexpr int kLog = 30;

class Trie {
  vector<int> value;
  vector<vector<int>> t;

  int add_node(const int level) {
    t.emplace_back(2);
    value.push_back(1 << level);
    return t.size() - 1;
  }

  int cost(const int x, const int y) {
    if (not t[x][0] and not t[x][1]) return 0;
    int ans = kInf;
    if (t[x][0] and t[y][0]) ans = min(ans, cost(t[x][0], t[y][0]));
    if (t[x][1] and t[y][1]) ans = min(ans, cost(t[x][1], t[y][1]));
    if (ans == kInf) {
      if (t[x][0] and t[y][1]) ans = min(ans, cost(t[x][0], t[y][1]) + value[x]);
      if (t[x][1] and t[y][0]) ans = min(ans, cost(t[x][1], t[y][0]) + value[x]);
    }
    return ans;
  }

public:
  Trie() {
    add_node(kLog - 1);
  }

  void add(const int num) {
    int x = 0;
    for (int i = kLog - 1; i >= 0; i--) {
      if (num & (1 << i)) {
        if (not t[x][1]) t[x][1] = add_node(i - 1);
        x = t[x][1];
      } else {
        if (not t[x][0]) t[x][0] = add_node(i - 1);
        x = t[x][0];
      }
    }
  }

  int64 calc_ans(const int x = 0) {
    int64 ans = 0;
    if (t[x][0] and t[x][1]) ans += cost(t[x][0], t[x][1]) + value[x];
    if (t[x][0]) ans += calc_ans(t[x][0]);
    if (t[x][1]) ans += calc_ans(t[x][1]);
    return ans;
  }
};

inline void solution() {
  const int n = read::Int();

  Trie t;
  for (int i = 0; i < n; i++) {
    t.add(read::Int());
  }

  cout << t.calc_ans() << '\n';
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