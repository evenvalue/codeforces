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

int64 inversions(const vector<int> &small, const vector<int> &big) {
  int64 ans = 0;
  for (const int x : small) {
    const auto it = upper_bound(big.begin(), big.end(), x);
    ans += distance(big.begin(), it);
  }
  return ans;
}

class Trie {
  vector<vector<int>> t;
  vector<vector<int>> index;
  vector<pair<int64, int64>> inv;

  int add_node() {
    t.emplace_back(2, 0);
    index.emplace_back();
    return t.size() - 1;
  }

  int dfs(const int x) {
    int dist = -1;
    for (const int y : t[x]) {
      if (not y) continue;
      dist = max(dist, dfs(y));
    }

    const int l = t[x][0];
    const int r = t[x][1];

    inv[dist].first += inversions(index[l], index[r]);
    inv[dist].second += inversions(index[r], index[l]);

    merge(index[l].begin(), index[l].end(),
          index[r].begin(), index[r].end(),
          back_inserter(index[x]));

    index[l].clear();
    index[r].clear();

    return dist + 1;
  }

public:
  Trie() : inv(kLog) {
    add_node();
  }

  void add(const string &s, const int label = -1) {
    int x = 0;
    for (const char c : s) {
      const int i = c - '0';
      if (not t[x][i]) t[x][i] = add_node();
      x = t[x][i];
    }
    index[x].push_back(label);
  }

  pair<int, int64> get_answer() {
    dfs(0);
    int x = 0;
    int64 ans = 0;
    for (int i = 0; i < kLog; i++) {
      if (inv[i].first <= inv[i].second) {
        ans += inv[i].first;
      } else {
        ans += inv[i].second;
        x += (1 << i);
      }
    }
    return {x, ans};
  }
};

string to_binary(const int x) {
  string ans(kLog, '-');
  for (int i = 0; i < kLog; i++) {
    ans[i] = ((x & (1 << i)) ? '1' : '0');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

inline void solution() {
  const int n = read::Int();

  Trie t;
  for (int i = 0; i < n; i++) {
    t.add(to_binary(read::Int()), i);
  }

  const auto [x, ans] = t.get_answer();
  cout << ans << ' ' << x << '\n';
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