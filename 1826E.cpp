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

namespace Read {
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
}//namespace Read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 5005;

using bit = bitset<kMaxN>;
inline void solution() {
  const int m = Read::Int();
  const int n = Read::Int();

  const vector<int> profit = Read::Vec<int>(n);

  vector<bit> better(n, bit{}.set());
  for (int city = 0; city < m; city++) {
    const vector<int> rating = Read::Vec<int>(n);

    vector<int> index(n);
    iota(index.begin(), index.end(), 0);

    sort(index.begin(), index.end(), [&](const int i, const int j) {
      return rating[i] > rating[j];
    });

    bit cur;
    for (int i = 0; i < n;) {
      const int rate = rating[index[i]];
      int j = i;
      while (i < n and rating[index[i]] == rate) {
        better[index[i]] &= cur;
        i++;
      }
      for (; j < i; j++) {
        cur[index[j]] = true;
      }
    }
  }

  vector<vector<int>> g(n);
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (better[x][y]) {
        g[x].push_back(y);
      }
    }
  }

  auto topsort = [&]() {
    vector<int> order;
    vector<bool> visit(n);
    function<void(int)> dfs = [&](const int x) {
      visit[x] = true;
      for (const int y : g[x]) {
        if (not visit[y]) dfs(y);
      }
      order.push_back(x);
    };
    for (int x = 0; x < n; x++) {
      if (not visit[x]) {
        dfs(x);
      }
    }
    return order;
  };

  const vector<int> order = topsort();

  vector<int64> ans(n);
  for (const int x : order) {
    ans[x] = profit[x];
    for (const int y : g[x]) {
      ans[x] = max(ans[x], ans[y] + profit[x]);
    }
  }

  cout << *max_element(ans.begin(), ans.end()) << '\n';
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