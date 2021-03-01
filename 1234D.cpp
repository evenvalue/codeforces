#include <iostream>
#include <vector>
using namespace std;

class SegTree {
  vector<int> tree;

  static int unite(int left, int right) {
    return left | right;
  }

public:
  explicit SegTree(int n) : tree(2 * n - 1, 0) {}

  void update(int x, int l, int r, int pos, char change) {
    if (l == pos and pos == r) {
      tree[x] = 1 << (change - 'a');
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (pos <= mid) {
      update(x + 1, l, mid, pos, change);
    } else {
      update(y, mid + 1, r, pos, change);
    }
    tree[x] = unite(tree[x + 1], tree[y]);
  }

  int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) {
      return tree[x];
    }
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
};

int bitcount(int x) {
  int ans = 0;
  while (x) {
    ans += x & 1;
    x >>= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  const int n = s.size();
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    st.update(0, 0, n - 1, i, s[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      st.update(0, 0, n - 1, pos - 1, c);
    } else {
      int l, r;
      cin >> l >> r;
      cout << bitcount(st.query(0, 0, n - 1, l - 1, r - 1)) << "\n";
    }
  }
}