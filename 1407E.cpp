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
  for (int i = index; i < n + index; i++) {
    v[i] = read<T>();
  }
  return v;
}

template<typename T>
vector<vector<T>> read_vec_vec(const int n, const int m, const int index_n = 0, const int index_m = 0) {
  vector<vector<T>> grid(n + index_n);
  for (int i = index_n; i < n + index_n; i++) {
    grid[i] = read_vec<T>(m, index_m);
  }
  return grid;
}

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read<int>();
  const int m = read<int>();

  vector<vector<int>> white(n);
  vector<vector<int>> black(n);
  for (int i = 0; i < m; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    auto &g = (read<int>() == 1 ? white : black);
    g[y].push_back(x);
  }

  vector<array<int, 2>> d(n, {kInf, kInf});

  auto dist = [&](const int x) {
    return max(d[x][0], d[x][1]);
  };

  queue<int> q;
  d[n - 1] = {0, 0};
  q.push(n - 1);

  vector<bool> visit(n);

  while (not q.empty()) {
    const int x = q.front();
    q.pop();
    for (const int y : white[x]) {
      if (d[y][1] > 1 + dist(x)) {
        d[y][1] = 1 + dist(x);
        if (d[y][1] == dist(y)) {
          q.push(y);
        }
      }
    }
    for (const int y : black[x]) {
      if (d[y][0] > 1 + dist(x)) {
        d[y][0] = 1 + dist(x);
        if (d[y][0] == dist(y)) {
          q.push(y);
        }
      }
    }
  }

  if (dist(0) == kInf) {
    d[0][0] = d[0][1] = -1;
  }

  cout << dist(0) << '\n';
  for (int x = 0; x < n; x++) {
    cout << (d[x][0] > d[x][1] ? 0 : 1);
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