#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

using int64 = int64_t;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

[[maybe_unused]] int readInt() {
  int x;
  cin >> x;
  return x;
}
[[maybe_unused]] int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
[[maybe_unused]] char readChar() {
  char c;
  cin >> c;
  return c;
}
[[maybe_unused]] string readString() {
  string s;
  cin >> s;
  return s;
}
[[maybe_unused]] double readDouble() {
  return stod(readString());
}
[[maybe_unused]] ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
[[maybe_unused]] pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
[[maybe_unused]] vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
[[maybe_unused]] vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

const int64 kInf64 = 2e18 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;


template<typename T>
class CoordinateCompression {
  bool sorted = false;
  vector<T> v;

public:
  void add(const T &x) {
    v.push_back(x);
  }

  void compress() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sorted = true;
  }

  int get(const int x) {
    if (not sorted) assert(false);
    return distance(v.begin(), lower_bound(v.begin(), v.end(), x));
  }
};

class SegTree {
  const int n;
  vector<int> t;

  static int unite(const int x, const int y) {
    return (x + y);
  }

  void update(const int x, const int l, const int r, const int p, const int inc) {
    if (l == r) {
      t[x] += inc;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (p <= mid) {
      update(x + 1, l, mid, p, inc);
    } else {
      update(y, mid + 1, r, p, inc);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  int query(const int x, const int l, const int r, const int ql, const int qr) {
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

  int query(const int x) {
    if (x == 1) return 0;
    return query(0, 0, n - 1, 1,x - 1);
  }

  void update(const int p, const int v) {
    update(0, 0, n - 1, p, v);
  }
};


void solution() {
  const int n = readInt();
  vector<int> a = readVec<int>(n);
  CoordinateCompression<int> cc;
  for (const int x : a)
    cc.add(x);
  cc.compress();
  for (int &x : a) {
    x = cc.get(x);
  }
  const int mx = *max_element(a.begin(), a.end()) + 5;
  SegTree st(n + 1);
  vector<int> left(mx), right(mx);
  for (const int x : a) {
    st.update(++right[x], 1);
  }
  int64 ans = 0;
  for (const int x : a) {
    st.update(right[x]--, -1);
    ans += st.query(++left[x]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solution();
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}