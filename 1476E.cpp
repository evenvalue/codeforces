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
constexpr int kMaxN = 2e5 + 10;

void reject() {
  cout << "NO\n";
  exit(0);
}

inline void solution() {
  const int n = Read::Int();
  const int m = Read::Int();
  const int k = Read::Int();

  vector<string> pattern(n);
  map<string, int> index;

  for (int i = 0; i < n; i++) {
    const string p = Read::String();
    pattern[i] = p;
    index[p] = i;
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    const string s = Read::String();
    const int match = Read::Int() - 1;

    vector<int> compatible;
    for (int mask = 0; mask < (1 << k); mask++) {
      string t = s;
      for (int bit = 0; bit < k; bit++) {
        if (mask & (1 << bit)) continue;
        t[bit] = '_';
      }
      if (index.find(t) != index.end()) {
        compatible.push_back(index[t]);
      }
    }

    sort(compatible.begin(), compatible.end(), [&](const int x, const int y) {
      return (x == match);
    });

    if (compatible.empty() or compatible[0] != match) reject();

    for (int j = 1; j < compatible.size(); j++) {
      g[compatible[j]].push_back(compatible[0]);
    }
  }

  vector<bool> enter(n);
  vector<bool> visit(n);

  function<bool(int)> find_cycle = [&](const int x) {
    visit[x] = enter[x] = true;
    bool found_cycle = false;
    for (const int y : g[x]) {
      if (enter[y]) found_cycle = true;
      if (visit[y]) continue;
      found_cycle |= find_cycle(y);
    }
    enter[x] = false;
    return found_cycle;
  };

  for (int x = 0; x < n; x++) {
    if (not visit[x] and find_cycle(x)) {
      reject();
    }
  }

  vector<int> order;
  function<void(int)> dfs = [&](const int x) {
    visit[x] = true;
    for (const int y : g[x]) {
      if (visit[y]) continue;
      dfs(y);
    }
    order.push_back(x);
  };

  fill(visit.begin(), visit.end(), false);
  for (int x = 0; x < n; x++) {
    if (not visit[x]) dfs(x);
  }

  cout << "YES\n";
  for (const int x : order) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
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