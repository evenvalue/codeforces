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
  int n;
  cin >> n;
  string s;
  cin >> s;
  auto check = [&](const int bit) -> int {
    int b = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (((i & 1) == bit) and s[i] == 'r') r++;
      else if (((i & 1) != bit) and s[i] == 'b') b++;
    }
    return max(r, b);
  };
  cout << min({check(0), check(1)}) << '\n';
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