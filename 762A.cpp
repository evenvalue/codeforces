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
  int k;
  cin >> n >> k;
  vector<int64> divisors;
  bool square = false;
  for (int64 i = 1; i * i <= n; i++) {
    if (n % i) continue;
    square = (i * i == n);
    divisors.push_back(i);
  }
  const int d = divisors.size();
  k += (k > d ? square : 0);
  if (2 * d < k) {
    cout << -1 << '\n';
  } else {
    cout << (k <= d ? divisors[k - 1] : n / divisors[2 * d - k]) << '\n';
  }
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