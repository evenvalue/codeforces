#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

namespace read {
int Int() {
  int x;
  cin >> x;
  return x;
}
int64 Int64() {
  int64 x;
  cin >> x;
  return x;
}
char Char() {
  char c;
  cin >> c;
  return c;
}
string String() {
  string s;
  cin >> s;
  return s;
}
double Double() {
  return stod(String());
}
ld LongDouble() {
  return stold(String());
}
template<typename T1, typename T2>
pair<T1, T2> Pair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> Vec(const int n) {
  vector<T> v(n);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> VecVec(const int n, const int m) {
  vector<vector<T>> v(n);
  for (vector<T> &vec : v) {
    vec = Vec<T>(m);
  }
  return v;
}
}//namespace read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
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

template<int N>
struct Vector {
  array<int64, N> v;

  Vector() = default;
  explicit Vector(const array<int64, N> &a) : v(a) {}

  int64 &operator[](const int i) {
    return v[i];
  }

  Vector<N> operator+(const Vector<N> &other) const {
    Vector ans{};
    for (int i = 0; i < N; i++) {
      ans[i] = v[i] + other.v[i];
      ans[i] -= (ans[i] >= kMod ? kMod : 0);
    }
    return ans;
  }
};

template<int N>
struct Matrix {
  array<array<int64, N>, N> mat;

  Matrix() = default;

  explicit Matrix(const array<array<int64, N>, N> &a) : mat(a) {}

  array<int64, N> &operator[](const int i) {
    return mat[i];
  }

  Matrix operator*(const Matrix &other) const {
    Matrix<N> ans{};
    for (auto &v : ans.mat) {
      for (auto &x : v) {
        x = 0;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          ans[i][k] += mat[i][j] * other.mat[j][k];
          ans[i][k] %= kMod;
        }
      }
    }
    return ans;
  }

  Vector<N> operator*(const Vector<N> &other) const {
    Vector<N> v{};
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        v[i] += mat[i][j] * other.v[j];
        v[i] %= kMod;
      }
    }
    return v;
  }

  Matrix<N> pow(int64 n) {
    Matrix<N> ans{};
    ans[0] = {1, 0};
    ans[1] = {0, 1};

    Matrix<N> cur = *this;
    while (n > 0) {
      if (n & 1) ans = ans * cur;
      cur = cur * cur;
      n >>= 1;
    }
    return ans;
  }
};

inline void solution() {
  const int n = read::Int();

  Matrix<2> mat{};
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 1;
  mat[1][1] = 0;

  mint den(2);

  for (int i = 0; i < n; i++) {
    const int64 x = read::Int64();
    mat = mat.pow(x);
    den = den.power(x);
  }

  Vector<2> v({0, 1});

  const mint p = mint((mat * v)[1]) / mint(2);
  const mint q = (den / mint(2));

  cout << p << "/" << q << '\n';
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