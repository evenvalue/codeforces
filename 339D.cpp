#include <iostream>
#include <vector>
using namespace std;

struct node {
  int val = 0;
  bool opr = true;
};

struct SegTree {
  vector<node> t;

  explicit SegTree(const int n) : t((2 * n) - 1) {}

  static node unite(node l, node r) {
    if (l.opr) {
      return {l.val | r.val, false};
    } else {
      return {l.val ^ r.val, true};
    }
  }

  void update(const int x, const int l, const int r, const int pos, const int upd) {
    if (l == r) {
      t[x].val = upd;
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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  n = 1 << n;
  vector<int> a(n);
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.update(0, 0, n - 1, i, a[i]);
  }
  while (m--) {
    int pos, upd;
    cin >> pos >> upd;
    st.update(0, 0, n - 1, pos - 1, upd);
    cout << st.t[0].val << "\n";
  }
}