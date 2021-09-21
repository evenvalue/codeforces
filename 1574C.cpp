#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = INT64_MAX;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define int int64_t

int take(const int attack, const int defend) {
  return max(0LL, defend - attack);
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  const int sum = accumulate(a.begin(), a.end(), 0LL);
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    const int idx = distance(a.begin(), lower_bound(a.begin(), a.end(), x));
    int ans = kInfL;
    if (idx != n) {
      ans = min(ans, take(a[idx], x) + take(sum - a[idx], y));
    }
    if (idx != 0) {
      ans = min(ans, take(a[idx - 1], x) + take(sum - a[idx - 1], y));
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}