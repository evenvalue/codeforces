#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using int64 = int64_t;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

int readInt() {
  int x;
  cin >> x;
  return x;
}
int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
char readChar() {
  char c;
  cin >> c;
  return c;
}
string readString() {
  string s;
  cin >> s;
  return s;
}
double readDouble() {
  return stod(readString());
}
ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

class SegTree {
  const int n;
  vector<int64> t;

  static int64 unite(const int64 l, const int64 r) {
    return l + r;
  }

  void update(const int x, const int l, const int r, const int p, const int64 v) {
    if (l == r) {
      t[x] += v;
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

  int64 query(const int x, const int l, const int r, const int ql, const int qr) {
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
  explicit SegTree(const int n) : n(n), t(2 * n - 1) {}

  void update(const int p, const int64 v) {
    assert(0 <= p and p < n);
    update(0, 0, n - 1, p, v);
  }

  int64 query(const int ql, const int qr) {
    assert(0 <= ql and ql <= qr and qr < n);
    return query(0, 0, n - 1, ql, qr);
  }
};

void solution() {
  const int n = readInt(), k = readInt() + 1;
  const vector<int> &a = readVec<int>(n);
  vector<SegTree> dp(k + 1, SegTree(n + 5));
  dp[0].update(0, 1), dp[1].update(a[0], 1);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= min(i + 1, k); j++) {
      dp[j].update(a[i], dp[j - 1].query(0, a[i] - 1));
    }
  }
  cout << dp[k].query(1, n) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  int testcases = 1;
  //  cin >> testcases;
  while (testcases--) {
    solution();
  }
}