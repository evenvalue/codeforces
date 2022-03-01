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

class Trie {
  vector<vector<int>> trie;
  vector<bool> is_terminal;

  int addNewNode() {
    trie.emplace_back(3, -1);
    is_terminal.push_back(false);
    return (int) is_terminal.size() - 1;
  }

public:
  Trie() : trie(1, vector<int>(3, -1)), is_terminal(1) {}

  void addString(const string &s) {
    int x = 0;
    for (const char ch : s) {
      const int c = ch - 'a';
      if (trie[x][c] == -1)
        trie[x][c] = addNewNode();
      x = trie[x][c];
    }
    is_terminal[x] = true;
  }

  bool dfs(const string &s, const int i = 0, const int x = 0, const int changed = 0) {
    if (changed >= 2) return false;
    if (i == s.size())
      return (changed == 1 and is_terminal[x]);
    for (const int c : {0, 1, 2}) {
      if (trie[x][c] == -1) continue;
      if (dfs(s, i + 1, trie[x][c], changed + ((char) (c + 'a') != s[i])))
        return true;
    }
    return false;
  }
};

void solution() {
  const int n = read::Int(), m = read::Int();
  Trie trie;
  for (int i = 0; i < n; i++)
    trie.addString(read::String());
  for (int i = 0; i < m; i++)
    cout << (trie.dfs(read::String()) ? "YES" : "NO") << '\n';
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