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

namespace cp {
class mo_s {
  struct query {
    int l, r, t;
    int ans;

    query(const int l, const int r, const int t) : l(l), r(r), t(t), ans(0) {}
  };

  const int kBlockSize = 500;
  const int n;
  const vector<int> &a;
  vector<query> queries;

  [[nodiscard]] int block_of(const int i) const {
    return i / kBlockSize;
  }


public:
  explicit mo_s(const vector<int> &a) : n(a.size()), a(a) {}

  void add_query(const int l, const int r, const int time) {
    assert(0 <= l and l <= r and r < n);
    queries.emplace_back(l, r, time);
  }

  vector<int> solve() {
    sort(queries.begin(), queries.end(), [&](const query &q1, const query &q2) {
      if (block_of(q1.l) != block_of(q2.l)) {
        return q1.l < q2.l;
      }
      return (block_of(q1.l) & 1 ? (q1.r < q2.r) : (q2.r < q1.r));
    });

    map<int, int> freq;
    int ans = 0;

    auto remove = [&](const int idx) {
      const int x = a[idx];
      int &fx = freq[x];
      if (fx == x) ans--;
      fx--;
      if (fx == x) ans++;
    };

    auto add = [&](const int idx) {
      const int x = a[idx];
      int &fx = freq[x];
      if (fx == x) ans--;
      fx++;
      if (fx == x) ans++;
    };

    for (int i = 0, l = 0, r = -1; i < queries.size(); i++) {
      while (l < queries[i].l) {
        remove(l);
        l++;
      }
      while (l > queries[i].l) {
        l--;
        add(l);
      }
      while (r < queries[i].r) {
        r++;
        add(r);
      }
      while (r > queries[i].r) {
        remove(r);
        r--;
      }
      queries[i].ans = ans;
    }

    sort(queries.begin(), queries.end(), [&](const query &q1, const query &q2) {
      return q1.t < q2.t;
    });

    vector<int> v(queries.size());
    for (int i = 0; const query &q : queries) {
      v[i] = q.ans;
      i++;
    }
    return v;
  }
};
}// namespace cp

void solution() {
  const int n = readInt(), m = readInt();
  const vector<int> &a = readVec<int>(n);
  cp::mo_s mo(a);
  for (int i = 0; i < m; i++) {
    const int l = readInt() - 1, r = readInt() - 1;
    mo.add_query(l, r, i);
  }
  const vector<int> &ans = mo.solve();
  for (const int x : ans) {
    cout << x << '\n';
  }
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