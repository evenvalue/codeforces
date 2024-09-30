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
constexpr int kMod = 998244353;
constexpr int kMaxN = 2e5 + 10;

template<unsigned int M>
struct modint {
  int64 x;

  modint(const modint<M> &m) : x(m.x) {}
  explicit modint(const int64 _x) : x((_x >= 0 ? _x % M : M + (_x % (int) M))) {}
  explicit modint(const int _x) : x((_x >= 0 ? _x % M : M + (_x % (int) M))) {}
  explicit modint() : x(0) {}

  [[nodiscard]] modint<M> inv() const {
    return power(M - 2);
  }

  [[nodiscard]] modint<M> power(int64 exp) const {
    modint<M> res(1), base(x);
    while (exp) {
      if (exp & 1) res *= base;
      base *= base;
      exp >>= 1;
    }
    return res;
  }

  [[nodiscard]] modint<M> power(modint<M> &exp) const {
    return power(exp.x);
  }

  modint<M> &operator=(const int _x) {
    x = (_x >= 0 ? _x % M : M + (_x % M));
    return *this;
  }

  modint<M> &operator=(const int64 _x) {
    x = (_x >= 0 ? _x % M : M + (_x % M));
    return *this;
  }

  modint<M> &operator=(const modint<M> &other) {
    x = other.x;
    return *this;
  }

  modint<M> &operator+=(const modint<M> &other) {
    x += other.x;
    x -= (x >= M ? M : 0);
    return *this;
  }

  modint<M> &operator-=(const modint<M> &other) {
    x += M - other.x;
    x -= (x >= M ? M : 0);
    return *this;
  }

  modint<M> &operator*=(const modint<M> &other) {
    x *= other.x;
    x %= M;
    return *this;
  }

  modint<M> &operator/=(const modint<M> &other) {
    x = (*this * other.inv()).x;
    return *this;
  }

  friend modint<M> operator+(const modint<M> &lhs, const modint<M> &rhs) {
    return (modint(lhs) += rhs);
  }

  friend modint<M> operator-(const modint<M> &lhs, const modint<M> &rhs) {
    return (modint(lhs) -= rhs);
  }

  friend modint<M> operator*(const modint<M> &lhs, const modint<M> &rhs) {
    return (modint(lhs) *= rhs);
  }

  friend modint<M> operator/(const modint<M> &lhs, const modint<M> &rhs) {
    return (modint(lhs) /= modint(rhs));
  }

  friend bool operator==(const modint<M> &lhs, const modint<M> &rhs) {
    return (lhs.x == rhs.x);
  }

  friend bool operator!=(const modint<M> &lhs, const modint<M> &rhs) {
    return (lhs.x != rhs.x);
  }

  friend std::ostream &operator<<(std::ostream &os, const modint<M> &m) {
    return (os << m.x);
  }

  friend std::istream &operator>>(std::istream &in, modint<M> &m) {
    return (in >> m.x);
  }

  modint<M> &operator++() {
    x++;
    x = (x == M ? 0 : x);
    return *this;
  }

  modint<M> &operator--() {
    x = (x == 0 ? M : x);
    x--;
    return *this;
  }

  modint<M> operator++(int) {
    modint result = *this;
    ++*this;
    return result;
  }

  modint<M> operator--(int) {
    modint result = *this;
    --*this;
    return result;
  }
};

using mint = modint<kMod>;

inline void solution() {
  const int n = read<int>();
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> deg(n);
  vector<int> p(n);

  function<void(int, int)> dfs = [&](const int x, const int par) {
    p[x] = par;
    for (const int y : g[x]) {
      if (y == par) continue;
      dfs(y, x);
      deg[x]++;
    }
  };

  vector<int> tmp;
  vector<int> alone;
  vector<int> value(n);

  auto process = [&](const int k) {
    tmp = deg;
    ranges::fill(value, 0);

    for (int x = 0; x < n; x++) {
      if (deg[x] == 0) alone.push_back(x);
    }

    while (not alone.empty()) {
      const int x = alone.back();
      alone.pop_back();

      if (const int m = value[x] % k; m != 0) {
        if (x != 0 and m == k - 1) {
          value[x]++;
        } else {
          return false;
        }
      } else {
        value[p[x]]++;
      }

      tmp[p[x]]--;
      if (tmp[p[x]] == 0) alone.push_back(p[x]);
    }

    return true;
  };

  dfs(0, 0);

  vector<mint> ans(n);
  ans[0] = mint(2).power(n - 1);
  for (int k = n; k >= 2; k--) {
    if ((n - 1) % k) continue;
    ans[k - 1] = process(k);
  }

  for (int k = n; k >= 1; k--) {
    for (int i = k + k; i <= n; i += k) {
      ans[k - 1] -= ans[i - 1];
    }
  }

  for (const auto &x : ans) {
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