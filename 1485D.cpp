#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
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
int64 binpow(int64 base, int64 pow, int64 mod) {
  int64 res = 1;
  while (pow) {
    if (pow & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    pow >>= 1;
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
struct Point {
  T x, y;

  //constructors
  [[maybe_unused]] explicit Point() = default;
  [[maybe_unused]] explicit Point(T x, T y) : x(x), y(y) {}

  //operators
  Point<T> operator+(const Point<T> &other) const {
    return Point<T>(x + other.x, y + other.y);
  }

  Point<T> &operator+=(const Point<T> &other) {
    return (*this = *this + other);
  }

  Point<T> operator-(const Point<T> &other) const {
    return Point<T>(x - other.x, y - other.y);
  }

  Point<T> &operator-=(const Point<T> &other) {
    return (*this = *this - other);
  }

  Point<T> &operator=(Point<T> other) {
    swap(x, other.x), swap(y, other.y);
    return *this;
  }

  bool operator==(const Point<T> &other) const {
    return (x == other.x and y == other.y);
  }

  bool operator!=(const Point<T> &other) const {
    return (x != other.x or y != other.y);
  }

  bool operator<(const Point<T> &other) const {
    return (x != other.x ? x < other.x : y < other.y);
  }

  friend ostream operator<<(ostream &out, const Point<T> &p);
  friend istream operator>>(istream &in, const Point<T> &p);
};

template<typename T>
ostream operator<<(ostream &out, const Point<T> &p) {
  out << p.x << ' ' << p.y;
}

template<typename T>
istream operator>>(istream &in, const Point<T> &p) {
  cin >> p.x >> p.y;
}

template<typename T>
Point<T> up(const Point<T> &p) {
  return p + Point<T>(0, 1);
}

template<typename T>
Point<T> down(const Point<T> &p) {
  return p + Point<T>(0, -1);
}

template<typename T>
Point<T> left(const Point<T> &p) {
  return p + Point<T>(-1, 0);
}

template<typename T>
Point<T> right(const Point<T> &p) {
  return p + Point<T>(1, 0);
}

template<typename T>
Point<T> clockwise90(const Point<T> &p) {
  return Point(p.y, -p.x);
}

template<typename T>
Point<T> anticlockwise90(const Point<T> &p) {
  return Point(-p.y, p.x);
}

template<typename T>
ld dist(const Point<T> &p1, const Point<T> &p2) {
  const ld run = p1.x - p2.x;
  const ld rise = p1.y - p2.y;
  return sqrt(binpow(run, 2) + binpow(rise, 2));
}


template<typename T, T e, class F = function<T(const T &, const T &)>>
class SegTree {
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
  [[maybe_unused]] explicit SegTree(const int n, F f) : t(2 * n - 1, e), n(n), unite(move(f)) {}
  [[maybe_unused]] explicit SegTree(const vector<T> &a, F f) : n(static_cast<int>(a.size())), unite(move(f)) {
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

template<typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
  const int n;
  vector<vector<T>> table;
  const F unite;

public:
  explicit SparseTable(const vector<T> &a, const F &f) : n(static_cast<int>(a.size())), unite(f) {
    const int height = 32 - __builtin_clz(n);
    table.resize(height);
    table[0] = a;
    for (int h = 1; h < height; h++) {
      table[h].resize(n - (1 << h) + 1);
      for (int i = 0; i <= n - (1 << h); i++) {
        table[h][i] = unite(table[h - 1][i], table[h - 1][i + (1 << (h - 1))]);
      }
    }
  }

  T get(const int l, const int r) const {
    assert(0 <= l && l <= r && r <= n - 1);
    const int log = 32 - __builtin_clz(r - l + 1) - 1;
    return unite(table[log][l], table[log][r - (1 << log) + 1]);
  }
};

int nexti() {
  int x;
  cin >> x;
  return x;
}

int64 nextll() {
  int64 x;
  cin >> x;
  return x;
}

char nextc() {
  char c;
  cin >> c;
  return c;
}

double nextd() {
  string s;
  cin >> s;
  return stod(s);
}

ld nextld() {
  string s;
  cin >> s;
  return stold(s);
}

template<typename T1, typename T2>
pair<T1, T2> nextp() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}

template<typename T>
vector<T> nextv(const int n) {
  vector<T> v(n);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}

string nexts() {
  string s;
  cin >> s;
  return s;
}


void _print(const int x) { cerr << x; }
void _print(const int64 x) { cerr << x; }
void _print(const double d, const int precision = 10) { cerr << fixed << setprecision(precision) << d; }
void _print(const ld d, const int precision = 10) { cerr << fixed << setprecision(precision) << d; }
void _print(const char c) { cerr << '\'' << c << '\''; }
void _print(const string &s) { cerr << '\"' << s << '\"'; }
template<typename T1, typename T2>
void _print(const pair<T1, T2> &p) {
  cerr << '[';
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << ']';
}
template<typename T>
void _print(const vector<T> &v) {
  const int n = v.size();
  cerr << '{';
  for (int i = 0; i < n; i++) {
    _print(v[i]);
    cerr << (i != n - 1 ? ", " : "");
  }
  cerr << '}';
}

void pline() { cout << '\n'; }
void pspace() { cout << ' '; }
void print(const int x) { cout << x; }
void print(const int64 x) { cout << x; }
void print(const double d, const int precision = 10) { cout << fixed << setprecision(precision) << d; }
void print(const ld d, const int precision = 10) { cout << fixed << setprecision(precision) << d; }
void print(const char c) { cout << c; }
void print(const string &s) { cout << s; }
template<typename T1, typename T2>
void print(const pair<T1, T2> &p) { print(p.first), pspace(), print(p.second); }
template<typename T>
void print(const vector<T> &v) {
  for (const T &x : v) {
    print(x), pspace();
  }
  pline();
}
template<typename T>
void print(const vector<vector<T>> &a) {
  for (const vector<T> &v : a) {
    print(v);
  }
}
}// namespace cp
using namespace cp;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve(const int testCase) {
  int l = 1;
  for (int i = 1; i <= 16; i++) l = lcm(l, i);
  const int n = nexti(), m = nexti();
  vector<vector<int>> a(n);
  for (vector<int> &row : a) row = nextv<int>(m);
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) & 1) {
        ans[i][j] = l + binpow(a[i][j], 4);
      } else {
        ans[i][j] = l;
      }
    }
  }
  print(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}