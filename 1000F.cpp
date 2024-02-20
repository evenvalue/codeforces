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

namespace Read {
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
}//namespace Read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 5e5 + 10;

class SegTree {
  const int n;
  vector<int> t;

  template<typename T>
  T unite(const T l, const T r) {
    return min(l, r);
  }

  void update(const int x, const int l, const int r, const int p, const int v) {
    if (l == r) {
      t[x] = v;
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

  pair<int, int> find_best(const int x, const int l, const int r) {
    if (l == r) {
      return {t[x], l};
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (t[x + 1] < t[y]) {
      return find_best(x + 1, l, mid);
    } else {
      return find_best(y, mid + 1, r);
    }
  }

  pair<int, int> query(const int x, const int l, const int r, const int ql, const int qr) {
    if (ql <= l and r <= qr) {
      return find_best(x, l, r);
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
  SegTree(const int n) : n(n), t(2 * n - 1, kInf) {}

  void update(const int p, const int v) {
    update(0, 0, n - 1, p, v);
  }

  pair<int, int> query(const int l, const int r) {
    return query(0, 0, n - 1, l, r);
  }
};

struct query {
  int i;
  int l;
  int r;
  int ans;
};

inline void solution() {
  const int n = Read::Int();
  const vector<int> a = Read::Vec<int>(n);

  const int q = Read::Int();
  vector<query> queries(q);

  for (int idx = 0; auto &[i, l, r, _] : queries) {
    i = idx++;
    l = Read::Int() - 1;
    r = Read::Int() - 1;
  }

  sort(queries.begin(), queries.end(), [](const query &x, const query &y) {
    return x.r < y.r;
  });

  SegTree st(n);
  vector<int> last(kMaxN, -1);

  for (int i = 0, j = 0; i < n; i++) {
    if (last[a[i]] != -1) st.update(last[a[i]], kInf);
    st.update(i, last[a[i]]);
    last[a[i]] = i;

    while (j != q and queries[j].r == i) {
      const auto [left, idx] = st.query(queries[j].l, queries[j].r);
      queries[j].ans = (left < queries[j].l ? a[idx] : 0);
      j++;
    }
  }

  sort(queries.begin(), queries.end(), [](const query &x, const query &y) {
    return x.i < y.i;
  });

  for (const query &qry : queries) {
    cout << qry.ans << '\n';
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