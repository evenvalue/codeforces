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
using max_heap = priority_queue<T, vector<T>, greater<T>>;

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

void solution() {
  const int n = readInt(), k = readInt();
  vector<int> a = readVec<int>(n);
  a.push_back(-kInf);

  multiset<int> inside;
  multiset<int, greater<>> outside;

  auto f = [&](const int l, const int r) -> int {
    int ans = accumulate(a.begin() + l, a.begin() + r + 1, 0);
    vector<pair<int, int>> op;
    while (op.size() < k and not outside.empty() and not inside.empty() and *outside.begin() > *inside.begin()) {
      const int o = *outside.begin(), i = *inside.begin();
      ans += o - i;
      op.emplace_back(o, i);
      outside.erase(outside.begin());
      inside.erase(inside.begin());
    }
    while (not op.empty()) {
      const auto [o, i] = op.back();
      outside.insert(o), inside.insert(i);
      op.pop_back();
    }
    return ans;
  };

  int ans = *max_element(a.begin(), a.end());

  for (int len = 2; len <= n; len++) {
    inside.clear(), outside.clear();
    for (int i = 0; i < len; i++) {
      inside.insert(a[i]);
    }
    for (int i = len; i <= n; i++) {
      outside.insert(a[i]);
    }
    for (int l = 0; l <= n - len; l++) {
      const int r = l + len - 1;
      ans = max(ans, f(l, r));
      inside.erase(inside.find(a[l])), outside.insert(a[l]);
      outside.erase(outside.find(a[r + 1])), inside.insert(a[r + 1]);
    }
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