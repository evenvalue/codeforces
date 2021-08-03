#include <algorithm>
#include <array>
#include <cassert>
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

void solve() {
  int64 n;
  cin >> n;
  int64 ans = kInfL;
  for (int i = 1; (int64)i * i <= n; i++) {
    if ((n % i != 0)) continue;
    if ((gcd(i, n / i) != 1)) continue;
    ans = min(ans, n / i);
  }
  cout << ans << ' ' << n / ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}