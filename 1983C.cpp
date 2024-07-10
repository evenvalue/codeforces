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

vector<pair<int, int>> ans;
auto check(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
  const int n = a.size();

  int total = accumulate(a.begin(), a.end(), 0LL);
  int each = (total + 2) / 3;

  int x = 0, y = 0, z = 0;
  int sa = kInf, sb = kInf, sc = kInf;
  for (int i = 0; i < n; i++) {
    if (x < each) {
      sa = min(sa, i);
      x += a[i];
    } else if (y < each) {
      sb = min(sb, i);
      y += b[i];
    } else {
      sc = min(sc, i);
      z += c[i];
    }
  }

  if (min({x, y, z}) < each) return false;

  ans = {{sa, sb - 1}, {sb, sc - 1}, {sc, n - 1}};
  return true;
}

inline void solution() {
  const int n = read<int>();
  auto a = read_vec<int>(n);
  auto b = read_vec<int>(n);
  auto c = read_vec<int>(n);

  vector<pair<int, int>> ret(3);
  if (check(a, b, c)) {
    ret = ans;
  } else if (check(a, c, b)) {
    ret[0] = ans[0];
    ret[1] = ans[2];
    ret[2] = ans[1];
  } else if (check(b, a, c)) {
    ret[0] = ans[1];
    ret[1] = ans[0];
    ret[2] = ans[2];
  } else if (check(b, c, a)) {
    ret[0] = ans[2];
    ret[1] = ans[0];
    ret[2] = ans[1];
  } else if (check(c, a, b)) {
    ret[0] = ans[1];
    ret[1] = ans[2];
    ret[2] = ans[0];
  } else if (check(c, b, a)) {
    ret[0] = ans[2];
    ret[1] = ans[1];
    ret[2] = ans[0];
  } else {
    cout << -1 << '\n';
    return;
  }

  for (const auto [x, y] : ret) {
    cout << x + 1 << ' ' << y + 1 << ' ';
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