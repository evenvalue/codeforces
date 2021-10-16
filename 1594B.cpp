#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;
using ld = long double;

namespace cp {
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int64 binpow(int64 base, int64 pow) {
  int64 res = 1;
  while (pow) {
    if (pow & 1) res *= base;
    base = (base * base);
    pow >>= 1;
  }
  return res;
}

int64 lcm(const int64 x, const int64 y) {
  return x / gcd(x, y) * y;
}

template<typename T>
struct point {
  T x, y;

  //constructors
  [[maybe_unused]] explicit point() = default;
  [[maybe_unused]] explicit point(T x, T y) : x(x), y(y) {}

  //operators
  point<T> operator+(const point<T> &other) const {
    return point<T>(x + other.x, y + other.y);
  }

  point<T> &operator+=(const point<T> &other) const {
    return (*this = *this + other);
  }

  point<T> operator-(const point<T> &other) const {
    return point<T>(x - other.x, y - other.y);
  }

  point<T> &operator-=(const point<T> &other) const {
    return (*this = *this - other);
  }

  point<T> &operator=(point<T> other) {
    swap(x, other.x), swap(y, other.y);
    return *this;
  }

  bool operator==(const point<T> &other) const {
    return (x == other.x and y == other.y);
  }

  bool operator!=(const point<T> &other) const {
    return (x != other.x or y != other.y);
  }

  friend ostream operator<<(ostream &out, const point<T> &p);
  friend istream operator>>(istream &in, const point<T> &p);
};

template<typename T>
ostream operator<<(ostream &out, const point<T> &p) {
  out << p.x << ' ' << p.y;
}

template<typename T>
istream operator>>(istream &in, const point<T> &p) {
  cin >> p.x >> p.y;
}

template<typename T>
point<T> up(const point<T> &p) {
  return p + point<T>(0, 1);
}

template<typename T>
point<T> down(const point<T> &p) {
  return p + point<T>(0, -1);
}

template<typename T>
point<T> left(const point<T> &p) {
  return p + point<T>(-1, 0);
}

template<typename T>
point<T> right(const point<T> &p) {
  return p + point<T>(1, 0);
}

template<typename T>
point<T> clockwise90(const point<T> &p) {
  return point(p.y, -p.x);
}

template<typename T>
point<T> anticlockwise90(const point<T> &p) {
  return point(-p.y, p.x);
}

template<typename T>
ld dist(const point<T> &p1, const point<T> &p2) {
  const ld run = p1.x - p2.x;
  const ld rise = p1.y - p2.y;
  return sqrt(binpow(run, 2) + binpow(rise, 2));
}


template<typename T, T e, class F = function<T(const T &, const T &)>>
class segtree {
  vector<T> t;
  const F unite;
  const int n;

  void build(const int x, const int l, const int r, const vector<T> &a) {
    if (l == r) {
      t[x] = a[l];
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    build(x + 1, l, mid, a);
    build(y, mid + 1, r, a);
    t[x] = unite(t[x + 1], t[y]);
  }

  void update(const int x, const int l, const int r, const int pos, const T &val) {
    if (l == r) {
      t[x] = val;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (pos <= mid) {
      update(x + 1, l, mid, pos, val);
    } else {
      update(y, mid + 1, r, pos, val);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  T query(const int x, const int l, const int r, const int ql, const int qr) {
    if (ql <= l and r <= qr) {
      return t[x];
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (qr <= mid) {
      return query(x + 1, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(y, mid + 1, r, ql, qr);
    } else {
      return unite(query(x + 1, l, mid, ql, qr), query(y, mid + 1, r, ql, qr));
    }
  }

  int find_first(const int x, const int l, const int r, const function<bool(T &)> &f) {
    if (l == r) {
      return l;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (f(t[x + 1])) {
      return find_first(x + 1, l, mid, f);
    } else {
      return find_first(y, mid + 1, r, f);
    }
  }

  int find_last(const int x, const int l, const int r, const function<bool(T &)> &f) {
    if (l == r) {
      return l;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (not f(t[y])) {
      return find_last(x + 1, l, mid, f);
    } else {
      return find_last(y, mid + 1, r, f);
    }
  }

public:
  [[maybe_unused]] explicit segtree(const int n, F f) : t(2 * n - 1, e), n(n), unite(move(f)) {}
  [[maybe_unused]] explicit segtree(const vector<T> &a, F f) : n(static_cast<int>(a.size())), unite(move(f)) {
    t.resize(2 * n - 1);
    build(0, 0, n - 1, a);
  }

  //Updates the value of a[pos] to val.
  //Complexity: O(log2 n)
  void set(const int pos, const T &val) {
    assert(0 <= pos and pos < n);
    update(0, 0, n - 1, pos, val);
  }

  //Finds unite(a[ql], a[ql + 1], ... , q[qr]).
  //Complexity: O(log2 n)
  T get(const int ql, const int qr) {
    assert(0 <= ql and ql <= qr and qr < n);
    return query(0, 0, n - 1, ql, qr);
  }

  //Finds the first i such that (0 <= i and i < n) and f(a[i]) returns true. If none, returns -1.
  //Complexity: O(log2 n)
  int first(const function<bool(T &)> f) {
    if (not f(t[0])) return -1;
    return find_first(0, 0, n - 1, f);
  }

  //Finds the last i such that (0 <= i and i < n) and f(a[i]) returns true. If none, returns -1.
  //Complexity: O(log2 n)
  int last(const function<bool(T &)> f) {
    if (not f(t[0])) return -1;
    return find_last(0, 0, n - 1, f);
  }
};

class dsu {
  const int n;
  vector<int> e;
  int groups;

  int find(const int x) {
    return (e[x] < 0 ? x : find(e[x]));
  }

public:
  //constructor
  explicit dsu(const int n) : n(n), e(n, -1), groups(n) {}

  //functions
  int leader(const int x) {
    assert(0 <= x and x < n);
    return find(x);
  }

  bool unite(int x, int y) {
    x = leader(x), y = leader(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }

  bool same(const int x, const int y) {
    return (leader(x) == leader(y));
  }

  int size(const int x) {
    return -e[leader(x)];
  }

  int components() const {
    return groups;
  }
};
}// namespace cp
using namespace cp;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(const int TestCase) {
  int n, k;
  cin >> n >> k;
  int64 ans = 0;
  for (int i = 0; i <= 31; i++) {
    if (k & (1LL << i)) {
      ans += binpow(n, i, kMod);
      ans -= (ans > kMod ? kMod : 0);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}