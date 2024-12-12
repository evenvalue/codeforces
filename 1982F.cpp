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
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

struct SegTree {
  struct node {
    int inc = 0;
    int min = 0;
    int max = 0;
  };

  static node unite(const node &l, const node &r) {
    node ans;
    ans.inc = l.inc + r.inc;
    ans.min = min(l.min, r.min);
    ans.max = max(l.max, r.max);
    return ans;
  };

  const int n;
  vector<node> t;

public:
  explicit SegTree(const int n) : n(n), t(2 * n) {}

  void update(int p, const node &val) {
    for (t[p += n] = val; p > 1; p >>= 1) {
      t[p >> 1] = unite(t[p], t[p ^ 1]);
    }
  }

  node query(int l, int r) {
    node res = {0, kInf, -kInf};
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = unite(res, t[l++]);
      if (r & 1) res = unite(res, t[--r]);
    }
    return res;
  }
};

inline void solution() {
  const int n = read<int>();
  auto a = read_vec<int>(n, 1);
  a.push_back(-kInf);

  SegTree st(n + 2);

  auto assign = [&](const int i) {
    st.update(i, {.inc = (a[i] <= a[i + 1]), .min = a[i], .max = a[i]});
  };

  for (int i = 1; i <= n; i++) {
    assign(i);
  }

  auto left_end = [&]() {
    if (a[1] > st.query(2, n).min) return 0;
    int lo = 1, hi = n - 1;
    while (lo < hi) {
      const int mid = (lo + hi + 1) / 2;
      auto cur = st.query(1, mid);
      if (cur.inc == mid and cur.max <= st.query(mid + 1, n).min) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  };

  auto right_end = [&]() {
    if (a[n] < st.query(1, n - 1).max) return n;
    int lo = 2, hi = n;
    while (lo < hi) {
      const int mid = (lo + hi + 1) / 2;
      auto cur = st.query(mid, n);
      if (cur.inc == n - mid and st.query(1, mid - 1).max <= cur.min) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }
    return lo;
  };

  auto calc = [&]() {
    if (st.query(1, n).inc == n - 1) {
      cout << -1 << ' ' << -1 << '\n';
      return;
    }
    const int l = left_end();
    const int r = right_end();
    cout << l + 1 << ' ' << r << '\n';
  };

  calc();

  const int q = read<int>();
  for (int qry = 0; qry < q; qry++) {
    const int i = read<int>();
    const int v = read<int>();
    a[i] = v;
    assign(i - 1);
    assign(i);
    calc();
  }
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