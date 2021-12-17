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

class mo_s {
  struct query {
    int l, r, v, t;
    int ans;

    query(const int l, const int r, const int v, const int t) : l(l), r(r), v(v), t(t), ans(0) {}
  };

  const int kBlockSize = 500;

  const int n;
  const vector<int> a;
  vector<query> queries;

  [[nodiscard]] int block_of(const int i) const {
    return i / kBlockSize;
  }

public:
  explicit mo_s(const vector<int> &a) : n(a.size()), a(a) {}

  void add_query(const int l, const int r, const int v, const int t) {
    queries.emplace_back(l, r, v, t);
  }

  vector<int> solve() {
    sort(queries.begin(), queries.end(), [&](const query &q1, const query &q2) {
      if (block_of(q1.l) != block_of(q2.l)) {
        return (q1.l < q2.l);
      }
      return (block_of(q1.l) & 1 ? q1.r < q2.r : q1.r > q2.r);
    });

    vector<int> freq(1e5 + 1);
    vector<int> at_least(1e5 + 1);

    auto add = [&](const int i) {
      freq[a[i]]++;
      at_least[freq[a[i]]]++;
    };

    auto rem = [&](const int i) {
      at_least[freq[a[i]]]--;
      freq[a[i]]--;
    };

    for (int i = 0, l = 0, r = -1; i < queries.size(); i++) {
      while (r < queries[i].r) {
        add(++r);
      }
      while (r > queries[i].r) {
        rem(r--);
      }
      while (l < queries[i].l) {
        rem(l++);
      }
      while (l > queries[i].l) {
        add(--l);
      }
      queries[i].ans = at_least[queries[i].v];
    }

    sort(queries.begin(), queries.end(), [](const query &q1, const query &q2) {
      return q1.t < q2.t;
    });
    vector<int> ans(queries.size());
    for (int i = 0; const query &q : queries) {
      ans[i++] = q.ans;
    }
    return ans;
  }
};

struct range {
  int l, r;
};

void solution() {
  const int n = readInt(), m = readInt();
  vector<int> c(n);
  for (int &x : c) {
    cin >> x;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = readInt() - 1, y = readInt() - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<range> subtree(n);
  vector<int> preorder;

  function<void(int, int)> dfs = [&](const int x, const int p) {
    subtree[x].l = preorder.size();
    preorder.push_back(c[x]);
    for (const int y : g[x]) {
      if (y == p) continue;
      dfs(y, x);
    }
    subtree[x].r = (int) preorder.size() - 1;
  };

  dfs(0, -1);
  mo_s mo(preorder);
  for (int i = 0; i < m; i++) {
    const int x = readInt() - 1, k = readInt();
    mo.add_query(subtree[x].l, subtree[x].r, k, i);
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