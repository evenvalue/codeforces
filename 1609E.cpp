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

template<class node, class F = std::function<node(const node &, const node &)>>
class SegTree {
  int n = 0;
  std::vector<node> t;
  F unite;

  void build(const int x, const int l, const int r, const std::vector<node> &a) {
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

  void update(const int x, const int l, const int r, const int p, const node &v) {
    if (l == p and p == r) {
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

  node query(const int x, const int l, const int r, const int ql, const int qr) const {
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
  SegTree() = default;
  explicit SegTree(const int n, const node e, F f) : n(n), t(2 * n - 1, e), unite(std::move(f)) {}
  explicit SegTree(const std::vector<node> &a, F f) : n(a.size()), t(2 * (a.size()) - 1), unite(std::move(f)) {
    build(0, 0, n - 1, a);
  }

  void update(const int p, const node &v) {
    assert(0 <= p and p < n);
    update(0, 0, n - 1, p, v);
  }

  [[nodiscard]] node query(const int l, const int r) const {
    assert(0 <= l and l <= r and r < n);
    return query(0, 0, n - 1, l, r);
  }
};

enum Type {
  a,
  b,
  c,
  ab,
  bc,
  abc
};

inline void solution(const auto &transitions) {
  const auto n = Read::Int();
  const auto q = Read::Int();
  const auto s = Read::String();

  using node = array<int, 6>;

  auto unite = [&](const node &left, const node &right) {
    node ans{};
    for (int i = 0; i < 6; i++) {
      ans[i] = kInf;
      for (const auto [l, r] : transitions[i]) {
        ans[i] = min(ans[i], left[l] + right[r]);
      }
    }
    return ans;
  };

  auto leaf = [](const char c) {
    node ans{};
    ans[c - 'a'] = 1;
    return ans;
  };

  vector<node> leaves(n);
  for (int i = 0; i < n; i++) {
    leaves[i] = leaf(s[i]);
  }

  SegTree<node> st(leaves, unite);

  for (int qry = 0; qry < q; qry++) {
    const int i = Read::Int() - 1;
    const char c = Read::Char();
    st.update(i, leaf(c));
    cout << st.query(0, n - 1)[Type::abc] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  array<vector<pair<Type, Type>>, 6> transitions;
  transitions[0] = {{Type::a, Type::a}};
  transitions[1] = {{Type::b, Type::b}};
  transitions[2] = {{Type::c, Type::c}};
  transitions[3] = {{Type::a, Type::ab}, {Type::ab, Type::b}};
  transitions[4] = {{Type::b, Type::bc}, {Type::bc, Type::c}};
  transitions[5] = {{Type::a, Type::abc}, {Type::ab, Type::bc}, {Type::abc, Type::c}};

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution(transitions);
  }
}