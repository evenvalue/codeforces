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

class PersistentSegTree {
  struct info {
    int best = 0;
    int pref = 0;
    int suff = 0;
    int size = 0;
  };

  struct node {
    info subarray;
    int l = -1;
    int r = -1;
  };

  const int n;
  vector<node> t;

  static info unite(const info &l, const info &r) {
    info ans;
    ans.best = max({l.best, r.best, l.suff + r.pref});
    ans.pref = (l.best == l.size ? l.best + r.pref : l.pref);
    ans.suff = (r.best == r.size ? l.suff + r.best : r.suff);
    ans.size = l.size + r.size;
    return ans;
  }

  int add_node() {
    const int x = t.size();
    t.emplace_back();
    return x;
  }

  int build(const int l, const int r) {
    const int x = add_node();
    if (l == r) {
      t[x].subarray = info({0, 0, 0, 1});
      return x;
    }
    const int mid = (l + r) / 2;
    t[x].l = build(l, mid);
    t[x].r = build(mid + 1, r);
    t[x].subarray = unite(t[t[x].l].subarray, t[t[x].r].subarray);
    return x;
  }

  int update(const int prev, const int l, const int r, const int pos) {
    const int x = add_node();
    t[x] = t[prev];
    if (l == r) {
      t[x].subarray = info({1, 1, 1, 1});
      return x;
    }
    const int mid = (l + r) / 2;
    if (pos <= mid) {
      t[x].l = update(t[prev].l, l, mid, pos);
    } else {
      t[x].r = update(t[prev].r, mid + 1, r, pos);
    }
    t[x].subarray = unite(t[t[x].l].subarray, t[t[x].r].subarray);
    return x;
  }

  info query(const int x, const int l, const int r, const int ql, const int qr) {
    if (ql <= l and r <= qr) {
      return t[x].subarray;
    }
    const int mid = (l + r) / 2;
    if (qr <= mid) {
      return query(t[x].l, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(t[x].r, mid + 1, r, ql, qr);
    } else {
      return unite(query(t[x].l, l, mid, ql, qr), query(t[x].r, mid + 1, r, ql, qr));
    }
  }

public:
  PersistentSegTree(const int n) : n(n) {}

  int build_tree() {
    return build(0, n - 1);
  }

  int update(const int x, const int pos) {
    return update(x, 0, n - 1, pos);
  }

  int query(const int root, const int ql, const int qr) {
    return query(root, 0, n - 1, ql, qr).best;
  }
};

inline void solution() {
  const int n = read::Int();
  vector<pair<int, int>> heights(n);
  for (int i = 0; i < n; i++) {
    heights[i] = {read::Int(), i};
  }

  sort(heights.rbegin(), heights.rend());

  PersistentSegTree pst(n);

  vector<int> root = {pst.build_tree()};
  for (auto [h, i] : heights) {
    root.push_back(pst.update(root.back(), i));
  }

  debug(root);

  int q = read::Int();
  while (q--) {
    const int l = read::Int() - 1;
    const int r = read::Int() - 1;
    const int w = read::Int();

    int lo = 0, hi = n;
    while (lo < hi) {
      const int mid = (lo + hi) / 2;
      if (pst.query(root[mid], l, r) < w) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    cout << heights[lo - 1].first << '\n';
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