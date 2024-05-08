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

template<typename T>
class FenwickTree {
  size_t n;
  vector<T> bit;

public:
  explicit FenwickTree(const size_t N) : n(N), bit(N, T{}) {}
  explicit FenwickTree(const vector<T> &a) : FenwickTree(a.size()) {
    n = a.size();
    for (int i = 0; i < n; i++) {
      update(i, a[i]);
    }
  }

  [[nodiscard]] T query(int r) const {
    T ans{};
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
      ans += bit[i];
    }
    return ans;
  }

  [[nodiscard]] T query(const int l, const int r) const {
    return query(r) - query(l - 1);
  }

  void update(const int i, const T delta) {
    for (int j = i; j < n; j |= j + 1) {
      bit[j] += delta;
    }
  }
};

inline void solution() {
  const int n = read<int>();
  const int q = read<int>();
  const auto a = read_vec<int>(n);

  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; i++) {
    const int l = read<int>() - 1;
    const int r = read<int>() - 1;
    queries[l].emplace_back(r, i);
  }

  vector<int> index(n + 1);
  for (int i = 0; i < n; i++) {
    index[a[i]] = i;
  }

  FenwickTree<int64> bit(n);
  vector<int64> dp(n);
  vector<int64> ans(q);

  for (int l = n - 1; l >= 0; l--) {
    const int x = a[l];
    dp[l] = 1;
    for (int y = x; y <= n; y += x) {
      for (int z = y + y; z <= n; z += y) {
        if (index[z] < index[y]) continue;
        dp[index[z]] += dp[index[y]];
      }
    }
    for (int y = x; y <= n; y += x) {
      bit.update(index[y], dp[index[y]]);
      dp[index[y]] = 0;
    }
    for (const auto [r, i] : queries[l]) {
      ans[i] = bit.query(l, r);
    }
  }

  for (const int64 x : ans) {
    cout << x << ' ';
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
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}