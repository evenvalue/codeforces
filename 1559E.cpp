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

mint ways(const vector<int> &a, const int m) {
  const int n = a.size();

  vector<mint> pref(m + 1);
  auto calc_pref = [&](const vector<mint> &v) {
    pref[0] = v[0];
    for (int i = 1; i <= m; i++) {
      pref[i] = pref[i - 1] + v[i];
    }
  };

  auto get = [&](const int l, const int r) {
    if (l <= 0) return pref[r];
    return pref[r] - pref[l - 1];
  };

  vector dp(2, vector<mint>(m + 1));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    calc_pref(dp[0]);
    for (int s = 0; s <= m; s++) {
      dp[1][s] = get(s - a[i], s);
    }
    swap(dp[0], dp[1]);
  }

  return accumulate(dp[0].begin(), dp[0].end(), mint(0));
}

inline void solution(vector<int> &primes) {
  const int n = read<int>();
  const int m = read<int>();

  vector<pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    l = read<int>();
    r = read<int>();
  }

  vector<int> x(n);
  mint ans;
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    int foo = i;
    for (const int p : primes) {
      if (foo % (p * p) == 0) {
        cnt = -2;
        break;
      } else if (foo % p == 0) {
        cnt++;
        foo /= p;
      }
    }
    if (foo != 1) cnt++;
    if (cnt < 0) continue;
    cnt = ((cnt & 1) ? -1 : 1);
    int s = m / i;
    for (int j = 0; j < n; j++) {
      const int l = (a[j].first + i - 1) / i;
      const int r = (a[j].second) / i;
      s -= l;
      x[j] = r - l;
      if (x[j] < 0) {
        s = -1;
        break;
      }
    }
    if (s < 0) continue;
    ans += mint(cnt) * ways(x, s);
  }
  cout << ans << '\n';
}

vector<int> sieve(const int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (not is_prime[i]) continue;
    for (int64 j = i * 1LL * i; j <= n; j += i) {
      is_prime[j] = false;
    }
    primes.push_back(i);
  }
  return primes;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  auto primes = sieve(350);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution(primes);
  }
}