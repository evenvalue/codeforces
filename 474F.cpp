#include <iostream>
#include <vector>
using namespace std;

int gcd (int x, int y) {
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

struct node {
  int val = 1;
  int freq = 0;
};

class SegTree {
  vector<node> t;

  static node unite(const node l, const node r) {
    int val = gcd(l.val, r.val);
    return {val, ((l.val == val) * l.freq) + ((r.val == val) * r.freq)};
  }

public:
  explicit SegTree(const int n) : t(2 * n - 1) {}

  void update(const int x, const int l, const int r, const int pos, const int upd) {
    if (l == r) {
      t[x] = {upd, 1};
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (pos <= mid) {
      update(x + 1, l, mid, pos, upd);
    } else {
      update(y, mid + 1, r, pos, upd);
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
};

int main() {
  int n;
  cin >> n;
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.update(0, 0, n - 1, i, x);
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << r - l + 1 - st.query(0, 0, n - 1, l - 1, r - 1).freq << "\n";
  }
}