#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

namespace evenvalue {
template<typename T, T(unite)(const T &, const T &), T e>
class SegTree {
  vector<int> t;
  const int n;

  void build(const int x, const int l, const int r, const vector<T> &a) {
    assert(0 <= l and l <= r and r < n);
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
    assert(0 <= l and l <= r and r < n);
    assert(l <= pos and pos <= r);
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
    assert(0 <= l and l <= r and r < n);
    assert(0 <= ql and ql <= qr and qr < n);
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
  explicit SegTree(const int n) : t(2 * n - 1, e), n(n) {}
  explicit SegTree(const vector<T> &a) : n(a.size()), t(2 * (int) (a.size()) - 1) {
    build(0, 0, n - 1, a);
  }

  void set(const int pos, const T &val) {
    update(0, 0, n - 1, pos, val);
  }

  T get(const int ql, const int qr) {
    return query(0, 0, n - 1, ql, qr);
  }
};
}// namespace evenvalue


int op_gcd(const int &x, const int &y) {
  return gcd(x, y);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  evenvalue::SegTree<int, op_gcd, 0> st(a);
  const int g = st.get(0, 2 * n - 1);
  int lo = 0;
  int hi = n - 1;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    bool same = true;
    for (int i = 0; i < n; i++) {
      same &= (g == st.get(i, i + mid));
      if (not same) break;
    }
    same ? (hi = mid) : (lo = mid + 1);
  }
  cout << lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}