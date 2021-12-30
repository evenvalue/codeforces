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

void solution() {
  const int n = readInt();
  vector<int> a = readVec<int>(n);
  sort(a.begin(), a.end());

  auto cntPairsThatSumToTarget = [&](const int64 target) {
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      const auto [lb, ub] = equal_range(a.begin() + i + 1, a.end(), target - a[i]);
      ans += (int)distance(lb, ub);
    }
    return ans;
  };

  int64 ans = 0;
  for (int64 i = 1; i <= (int)2e9; i += i) {
    ans += cntPairsThatSumToTarget(i);
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