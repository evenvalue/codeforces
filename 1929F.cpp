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
  const int c = read<int>();

  vector<int> val(n);
  vector<pair<int, int>> g(n);
  for (int x = 0; x < n; x++) {
    g[x].first = max(-1, read<int>() - 1);
    g[x].second = max(-1, read<int>() - 1);
    val[x] = read<int>();
  }

  vector<int> order = {1};
  function<void(int)> dfs = [&](const int x) {
    if (x == -1) return;
    dfs(g[x].first);
    order.push_back(val[x]);
    dfs(g[x].second);
  };

  dfs(0);

  mint ans(1);

  order.push_back(c);
  for (int i = 0; i < order.size() - 1;) {
    int j = i + 1;
    while (order[j] == -1) {
      j++;
    }
    const int x = order[j] - order[i];
    const int y = j - i - 1;
    for (int k = x + 1; k <= x + y; k++) {
      ans *= mint(k) / mint(k - x);
    }
    i = j;
  }

  cout << ans << '\n';
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