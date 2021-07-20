#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

pair<int64, int64> solve() {
  int64 a, b;
  cin >> a >> b;
  if (a == b) return {0, 0};
  const int64 g = abs(a - b);
  return {g, min(a % g, g - (a % g))};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    auto [mx, mn] = solve();
    cout << mx << ' ' << mn << '\n';
  }
}