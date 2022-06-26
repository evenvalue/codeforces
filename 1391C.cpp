#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

int fact(const int n) {
  int64 f = 1;
  for (int i = 1; i <= n; i++) {
    f *= i;
    f %= kMod;
  }
  return f;
}

int pow2(const int n) {
  int p = 1;
  for (int pow = 1; pow <= n; pow++) {
    p += p;
    p -= (p > kMod ? kMod : 0);
  }
  return p;
}

void solve() {
  int n;
  cin >> n;
  cout << (fact(n) - pow2(n - 1) + kMod) % kMod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}