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

struct SegTree {
  struct node {
    int sum = 0;
    bool lazy = false;
  };

  const int n;
  vector<node> t;

  static node unite(const node l, const node r) {
    node ans;
    ans.sum = l.sum + r.sum;
    return ans;
  }

  void push(const int x, const int l, const int r) {
    if (not t[x].lazy) return;
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;

    for (const int child : {x + 1, y}) {
      t[child].sum = 0;
      t[child].lazy = true;
    }

    t[x].lazy = false;
  }

  void unmark(const int x, const int l, const int r, const int ql, const int qr) {
    if (ql <= l and r <= qr) {
      t[x].sum = 0;
      t[x].lazy = true;
      return;
    }
    push(x, l, r);
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (ql <= mid) {
      unmark(x + 1, l, mid, ql, qr);
    }
    if (mid < qr) {
      unmark(y, mid + 1, r, ql, qr);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  void mark(const int x, const int l, const int r, const int pos) {
    if (l == r) {
      t[x].sum = 1;
      return;
    }
    push(x, l, r);
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (pos <= mid) {
      mark(x + 1, l, mid, pos);
    } else {
      mark(y, mid + 1, r, pos);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  node query(const int x, const int l, const int r, const int ql, const int qr) {
    if (ql <= l and r <= qr) {
      return t[x];
    }
    push(x, l, r);
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (qr <= mid) {
      return query(x + 1, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(y, mid + 1, r, ql, qr);
    } else {
      return unite(query(x + 1, l, mid, ql, qr),
                   query(y, mid + 1, r, ql, qr));
    }
  }

public:
  explicit SegTree(const int n) : n(n), t(2 * n - 1) {
    for (int i = 0; i < n; i++) {
      mark(0, 0, n - 1, i);
    }
  }

  void mark(const int pos) {
    mark(0, 0, n - 1, pos);
  }

  void unmark(const int l, const int r) {
    unmark(0, 0, n - 1, l, r);
  }

  bool empty(const int l, const int r) {
    return (query(0, 0, n - 1, l, r).sum > 0);
  }
};

struct range {
  int l, r;
};

inline void solution() {
  const int n = read::Int();

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1;
    const int y = read::Int() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> parent(n);
  vector<range> subtree(n);
  function<int(int, int, int)> dfs = [&](const int x, const int p, int time) {
    subtree[x].l = time;
    parent[x] = p;
    for (const int y : g[x]) {
      if (y == p) continue;
      time = dfs(y, x, time + 1);
    }
    subtree[x].r = time;
    return time;
  };

  dfs(0, -1, 0);

  SegTree st(n);

  int q = read::Int();
  while (q--) {
    const int type = read::Int();
    const int x = read::Int() - 1;
    if (type == 1) {
      if (x != 0 and st.empty(subtree[x].l, subtree[x].r)) {
        st.mark(subtree[parent[x]].l);
      }
      st.unmark(subtree[x].l, subtree[x].r);
    } else if (type == 2) {
      st.mark(subtree[x].l);
    } else {
      cout << not st.empty(subtree[x].l, subtree[x].r) << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}