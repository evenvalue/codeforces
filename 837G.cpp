#include <bits/stdc++.h>
using namespace std;

#define int long long

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
constexpr int kMod = 1e9;
constexpr int kMaxN = 2e5 + 10;
constexpr int kMaxX = 2e5 + 10;

struct line {
  int m = 0;
  int c = 0;

  line() = default;
  line(const int m, const int c) : m(m), c(c) {}

  int f(const int x) const {
    return m * x + c;
  }

  line operator+(const line &other) const {
    return {m + other.m, c + other.c};
  }

  line &operator+=(const line &other) {
    m += other.m;
    c += other.c;
    return *this;
  }

  bool operator==(const line &other) const {
    return m == other.m and c == other.c;
  }
};

class PersistentSegTree {
  struct node {
    line val;
    int l = -1;
    int r = -1;
  };

  const int n;
  vector<node> t;

  int add_node() {
    const int x = t.size();
    t.emplace_back();
    return x;
  }

  int build(const int l, const int r, const vector<line> &a) {
    const int x = add_node();
    if (l == r) {
      t[x].val = a[l];
      return x;
    }
    const int mid = (l + r) / 2;
    t[x].l = build(l, mid, a);
    t[x].r = build(mid + 1, r, a);
    return x;
  }

  int update(const int prev, const int l, const int r, const int ql, const int qr, const line upd) {
    const int x = add_node();
    t[x] = t[prev];
    if (ql <= l and r <= qr) {
      t[x].val += upd;
      return x;
    }
    const int mid = (l + r) / 2;
    if (ql <= mid) {
      t[x].l = update(t[x].l, l, mid, ql, qr, upd);
    }
    if (mid < qr) {
      t[x].r = update(t[x].r, mid + 1, r, ql, qr, upd);
    }
    return x;
  }

  int query(const int x, const int l, const int r, const int pos) {
    if (l == r) {
      return t[x].val.f(pos);
    }
    const int mid = (l + r) / 2;
    if (pos <= mid) {
      return query(t[x].l, l, mid, pos) + t[x].val.f(pos);
    } else {
      return query(t[x].r, mid + 1, r, pos) + t[x].val.f(pos);
    }
  }

public:
  explicit PersistentSegTree(const int n) : n(n) {}

  int build_tree(const vector<line> &a) {
    return build(0, n - 1, a);
  }

  int update(const int root, const int ql, const int qr, const line upd) {
    return update(root, 0, n - 1, ql, qr, upd);
  }

  int query(const int root, const int pos) {
    return query(root, 0, n - 1, pos);
  }
};

inline void solution() {
  const int n = read::Int();

  vector<int> root;

  PersistentSegTree pst(kMaxX + 1);
  root.push_back(pst.build_tree(vector<line>(kMaxX + 1)));

  for (int i = 1; i <= n; i++) {
    const int x1 = read::Int();
    const int x2 = read::Int();
    const int y1 = read::Int();
    const int m = read::Int();
    const int c = read::Int();
    const int y2 = read::Int();

    const line l1 = line(0, y1);
    const line l2 = line(m, c);
    const line l3 = line(0, y2);

    const int r0 = root.back();
    const int r1 = pst.update(r0, 0, x1, l1);
    const int r2 = pst.update(r1, x1 + 1, x2, l2);
    const int r3 = pst.update(r2, x2 + 1, kMaxX, l3);
    root.push_back(r3);
  }

  const int q = read::Int();
  for (int qry = 0, last = 0; qry < q; qry++) {
    const int l = read::Int();
    const int r = read::Int();
    const int x = (last + read::Int()) % kMod;

    last = pst.query(root[r], x) - pst.query(root[l - 1], x);
    cout << last << '\n';
  }
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