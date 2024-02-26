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
constexpr int kMaxN = 2e5 + 10;

class SegTree {
  const int n;
  vector<int> t;

  static int unite(const int x, const int y) {
    return min(x, y);
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

  int query(const int x, const int l, const int r, const int ql) {
    if (l == r) return l;
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (t[x + 1] < ql) {
      return query(x + 1, l, mid, ql);
    } else {
      return query(y, mid + 1, r, ql);
    }
  }

public:
  SegTree(const int n) : n(n), t(2 * n - 1, -1) {}

  void update(const int p, const int v) {
    update(0, 0, n - 1, p, v);
  }

  int query(const int l) {
    return query(0, 0, n - 1, l);
  }
};

struct query {
  int l;
  int r;
};

inline void solution() {
  const int n = Read::Int();
  vector<vector<int>> occ(n + 2, vector<int>(1, -1));

  vector<int> a = Read::Vec<int>(n);
  for (int i = 0; int &x : a) {
    x--;
    occ[x].push_back(i++);
  }

  for (vector<int> &v : occ) {
    v.push_back(n);
  }

  vector<query> queries;
  for (int x = 0; x <= n; x++) {
    for (int i = 0; i < occ[x].size(); i++) {
      const int l = occ[x][i] + 1;
      const int r = occ[x][i + 1] - 1;
      if (l <= r) queries.push_back({l, r});
    }
  }

  sort(queries.begin(), queries.end(), [](const query &q1, const query &q2) {
    return q1.r < q2.r;
  });


  vector<bool> is_mex(n + 2);
  SegTree st(n + 2);

  for (int i = 0, j = 0; i < n; i++) {
    st.update(a[i], i);
    while (j != queries.size() and queries[j].r == i) {
      is_mex[st.query(queries[j].l)] = true;
      j++;
    }
  }

  for (int i = 0; i <= n + 1; i++) {
    if (not is_mex[i]) {
      cout << i + 1 << '\n';
      return;
    }
  }

  assert(false);
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