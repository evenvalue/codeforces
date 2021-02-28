#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define int int64_t

struct node {
  int value = 0;
  int lazy = 0;
};

class SegTree {
  vector<node> tree;

  static node unite(const node &left, const node &right) {
    return {min(left.value, right.value), 0};
  }

  void push(int x, int l, int r) {
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    const int lazy = tree[x].lazy;
    tree[x + 1].value += lazy;
    tree[y].value += lazy;
    tree[x + 1].lazy += lazy;
    tree[y].lazy += lazy;
    tree[x].lazy = 0;
  }

public:
  explicit SegTree(int n) : tree((2 * n) - 1) {}

  node query(int x, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) {
      return tree[x];
    }
    push(x, l, r);
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (qr <= mid) {
      return query(x + 1, l, mid, ql, qr);
    } else if (ql > mid) {
      return query(y, mid + 1, r, ql, qr);
    } else {
      return unite(query(x + 1, l, mid, ql, qr), query(y, mid + 1, r, ql, qr));
    }
  }

  void update(int x, int l, int r, int ql, int qr, int inc) {
    if (ql <= l and r <= qr) {
      // apply the update to interval.
      tree[x].value += inc;
      tree[x].lazy += inc;
      return;
    }
    push(x, l, r);
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (ql <= mid) {
      update(x + 1, l, mid, ql, qr, inc);
    }
    if (mid < qr) {
      update(y, mid + 1, r, ql, qr, inc);
    }
    tree[x] = unite(tree[x + 1], tree[y]);
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.update(0, 0, n - 1, i, i, x);
  }
  int m;
  cin >> m;
  for (int q = 1; q <= m; q++) {
    string s;
    while (s.empty()) getline(cin, s);
    stringstream ss(s);
    int l, r, inc;
    ss >> l >> r;
    if (ss >> inc) {
      if (r < l) {
        st.update(0, 0, n - 1, l, n - 1, inc);
        st.update(0, 0, n - 1, 0, r, inc);
      } else {
        st.update(0, 0, n - 1, l, r, inc);
      }
    } else {
      if (r < l) {
        int ans1 = st.query(0, 0, n - 1, l, n - 1).value;
        int ans2 = st.query(0, 0, n - 1, 0, r).value;
        cout << min(ans1, ans2) << "\n";
      } else {
        cout << st.query(0, 0, n - 1, l, r).value << "\n";
      }
    }
  }
}