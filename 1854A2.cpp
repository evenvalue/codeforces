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

auto try_positive(const vector<int> &a) {
  const int n = a.size();

  int mx = 0, mn = 0;
  int pick = -1;

  for (int i = 0; i < n; i++) {
    const int x = a[i];
    mx = max(mx, x);
    mn = min(mn, x);
    if (mx == x) pick = i;
  }

  if (mx == 0) {
    return vector<pair<int, int>>(20, {-1, -1});
  }

  vector<pair<int, int>> ans;
  while (mx < -mn) {
    ans.emplace_back(pick, pick);
    mx += mx;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      ans.emplace_back(i, pick);
    }
  }

  return ans;
}

auto try_negative(const vector<int> &a) {
  const int n = a.size();

  int mx = 0, mn = 0;
  int pick = -1;

  for (int i = 0; i < n; i++) {
    const int x = a[i];
    mx = max(mx, x);
    mn = min(mn, x);
    if (mn == x) pick = i;
  }

  if (mn == 0) {
    return vector<pair<int, int>>(20, {-1, -1});
  }

  vector<pair<int, int>> ans;
  while (-mn < mx) {
    ans.emplace_back(pick, pick);
    mn += mn;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      ans.emplace_back(i, pick);
    }
  }

  return ans;
}

inline void solution() {
  const int n = read<int>();
  const auto a = read_vec<int>(n);

  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << '\n';
    return;
  }

  int mx = 0;
  for (const int x : a) {
    mx = max(mx, abs(x));
  }

  const auto ans1 = try_positive(a);
  const auto ans2 = try_negative(a);
  auto ans = (ans1.size() <= ans2.size() ? ans1 : ans2);

  assert(ans.size() <= 12);

  if (ans1.size() <= ans2.size()) {
    for (int i = 1; i < n; i++) {
      ans.emplace_back(i, i - 1);
    }
  } else {
    for (int i = n - 2; i >= 0; i--) {
      ans.emplace_back(i, i + 1);
    }
  }

  cout << ans.size() << '\n';
  for (const auto [i, j] : ans) {
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
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