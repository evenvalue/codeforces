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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m & 1) {
    swap(n, m);
    k = ((n * m) / 2) - k;
  }
  if (n & 1) {
    if (k < m / 2) {
      cout << "NO\n";
      return;
    }
    k -= m / 2;
  }
  cout << (k & 1 ? "NO" : "YES") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}