#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
T read() {
  T x;
  cin >> x;
  return x;
}

template<typename T1, typename T2>
pair<T1, T2> read_pair() {
  pair<T1, T2> p;
  cin >> p.first;
  cin >> p.second;
  return p;
}

template<typename T>
vector<T> read_vec(const int n, const int index = 0) {
  vector<T> v(n + index);
  for (int i = index; i < n + index; i++) { v[i] = read<T>(); }
  return v;
}

template<typename T>
vector<vector<T>> read_vec_vec(const int n, const int m, const int index_n = 0, const int index_m = 0) {
  vector<vector<T>> grid(n + index_n);
  for (int i = index_n; i < n + index_n; i++) { grid[i] = read_vec<T>(m, index_m); }
  return grid;
}

constexpr int kAlphaSize = 62;
constexpr int kNodes = kAlphaSize * kAlphaSize;

int char_to_int(const char c) {
  if ('a' <= c and c <= 'z') return c - 'a';
  if ('A' <= c and c <= 'Z') return c - 'A' + 26;
  if ('0' <= c and c <= '9') return c - '0' + 52;
}

char int_to_char(const int i) {
  if (i < 26) return 'a' + i;
  if (i < 52) return 'A' + i - 26;
  return '0' + i - 52;
}

int node(const char c1, const char c2) {
  return char_to_int(c1) * kAlphaSize + char_to_int(c2);
}

pair<char, char> decode(const int x) {
  return make_pair(int_to_char(x / kAlphaSize), int_to_char(x % kAlphaSize));
}

void reject() {
  cout << "NO\n";
  exit(0);
}

inline void solution() {
  const int n = read<int>();
  vector<vector<int>> g(kNodes);

  vector<int> in_deg(kNodes), out_deg(kNodes);

  for (int i = 0; i < n; i++) {
    auto s = read<string>();
    const int x = node(s[0], s[1]);
    const int y = node(s[1], s[2]);
    g[x].push_back(y);
    out_deg[x]++;
    in_deg[y]++;
  }

  int start = -1, end = -1;
  for (int i = 0; i < kNodes; i++) {
    if (out_deg[i] == in_deg[i]) continue;
    if (out_deg[i] - in_deg[i] == 1) {
      if (start != -1) reject();
      start = i;
    } else if (out_deg[i] - in_deg[i] == -1) {
      if (end != -1) reject();
      end = i;
    } else {
      reject();
    }
  }

  if (start == -1) {
    for (int i = 0; i < kNodes; i++) {
      if (not g[i].empty()) start = i;
    }
  }

  vector<int> path;
  function<void(int)> dfs = [&](const int x) {
    while (not g[x].empty()) {
      const int y = g[x].back();
      g[x].pop_back();
      dfs(y);
    }
    path.push_back(x);
  };

  dfs(start);

  reverse(path.begin(), path.end());

  if (path.size() != n + 1) {
    reject();
  }

  assert(path[0] == start);

  string ans = {decode(start).first};
  for (const int x : path) {
    ans += decode(x).second;
  }

  cout << "YES\n";
  cout << ans << '\n';
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