#include <bits/stdc++.h>
using namespace std;

#define int long long

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
  const int s = read<int>();
  const int e = read<int>();

  const auto x = read_vec<int>(n, 1);
  const auto a = read_vec<int>(n, 1);
  const auto b = read_vec<int>(n, 1);
  const auto c = read_vec<int>(n, 1);
  const auto d = read_vec<int>(n, 1);

  auto cost_incoming = [&](const int i, const int incoming) {
    return (incoming == 1 ? x[i] + a[i] : -x[i] + b[i]);
  };

  auto cost_outgoing = [&](const int i, const int outgoing) {
    return (outgoing == 1 ? x[i] + c[i] : -x[i] + d[i]);
  };

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, kInf64));

  auto transition = [&](const int i, const int j, const int in, const int out) {
    const int prev_j = j + ((in + out) / 2);
    if (prev_j < 0 or prev_j > n) return;
    if (prev_j == 0 and i != 1) return;
    dp[i][j] = min(dp[i][j], dp[i - 1][prev_j] + cost_incoming(i, in) + cost_outgoing(i, out));
  };


  bool seen_s = false;
  bool seen_e = false;

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i == s) {
      if (seen_e) {
        seen_e = false;
      } else {
        seen_s = true;
      }
    } else if (i == e) {
      if (seen_s) {
        seen_s = false;
      } else {
        seen_e = true;
      }
    }
    for (int j = 0; j <= n; j++) {
      if (i == s) {
        const int direction = (s - e) / abs(s - e);
        transition(i, j, direction, 1);
        transition(i, j, direction, -1);
      } else if (i == e) {
        const int direction = (e - s) / abs(s - e);
        transition(i, j, 1, direction);
        transition(i, j, -1, direction);
      } else {
        transition(i, j, 1, 1);
        if (not seen_e or j != 1) {
          transition(i, j, 1, -1);
        }
        if (not seen_s or j != 1) {
          transition(i, j, -1, 1);
        }
        transition(i, j, -1, -1);
      }
    }
  }

  cout << dp[n][0] - cost_incoming(s, (s - e) / abs(s - e)) - cost_outgoing(e, (e - s) / abs(s - e)) << '\n';
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