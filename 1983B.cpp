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
  auto foo_a = read_vec<string>(n);
  auto foo_b = read_vec<string>(n);

  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = foo_a[i][j] - '0';
      b[i][j] = foo_b[i][j] - '0';
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      while (a[i][j] != b[i][j]) {
        (a[i][j] += 1) %= 3;
        (a[i + 1][j + 1] += 1) %= 3;
        (a[i + 1][j] += 2) %= 3;
        (a[i][j + 1] += 2) %= 3;
      }
    }
  }

  bool yes = true;
  for (int i = 0; i < n; i++) {
    yes &= (a[i] == b[i]);
  }

  cout << (yes ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}