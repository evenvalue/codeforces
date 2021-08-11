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
  int64 n, x;
  cin >> n;
  x = n;
  vector<int64> primes;
  for (int i = 2; (int64)i * i <= n; i++) {
    if (x % i) continue;
    while (x % i == 0) {
      x /= i;
      primes.push_back(i);
    }
  }
  if (x > 1) primes.push_back(x);
  if (primes.size() == 2) {
    cout << 2 << '\n';
    return;
  }
  cout << 1 << '\n' << (primes.size() <= 1 ? 0 : (int64)primes[0] * primes[1]) << '\n';
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