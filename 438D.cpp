#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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

class SegTree {
  struct node {
    int64 sum = 0;
    int64 max = 0;

    node() = default;
    explicit node(const int64 x) : sum(x), max(x) {}
  };

  const int n;
  vector<node> t;

  static node unite(const node l, const node r) {
    node ans;
    ans.sum = l.sum + r.sum;
    ans.max = max(l.max, r.max);
    return ans;
  }

  void build(const int x, const int l, const int r, const vector<int> &a) {
    if (l == r) {
      t[x] = node(a[l]);
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    build(x + 1, l, mid, a);
    build(y, mid + 1, r, a);
    t[x] = unite(t[x + 1], t[y]);
  }

  void modulo(const int x, const int l, const int r, const int ql, const int qr, const int m) {
    if (t[x].max < m) return;
    if (l == r) {
      t[x] = node(t[x].sum % m);
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (ql <= mid) {
      modulo(x + 1, l, mid, ql, qr, m);
    }
    if (mid < qr) {
      modulo(y, mid + 1, r, ql, qr, m);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  void update(const int x, const int l, const int r, const int p, const int v) {
    if (l == r) {
      t[x] = node(v);
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (p <= mid) {
      update(x + 1, l, mid, p, v);
    } else {
      update(y, mid + 1, r, p, v);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  node query(const int x, const int l, const int r, const int ql, const int qr) {
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

public:
  explicit SegTree(const vector<int> &a) : n(a.size()), t(2 * n - 1) {
    build(0, 0, n - 1, a);
  }

  void modulo(const int l, const int r, const int m) {
    modulo(0, 0, n - 1, l, r, m);
  }

  void update(const int p, const int v) {
    update(0, 0, n - 1, p, v);
  }

  int64 query(const int l, const int r) {
    return query(0, 0, n - 1, l, r).sum;
  }
};

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();

  vector<int> a = read::Vec<int>(n);
  SegTree st(a);

  for (int i = 0; i < m; i++) {
    const int t = read::Int();
    if (t == 1) {
      const int l = read::Int() - 1;
      const int r = read::Int() - 1;
      cout << st.query(l, r) << '\n';
    } else if (t == 2) {
      const int l = read::Int() - 1;
      const int r = read::Int() - 1;
      const int x = read::Int();
      st.modulo(l, r, x);
    } else {
      const int p = read::Int() - 1;
      const int v = read::Int();
      st.update(p, v);
    }
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