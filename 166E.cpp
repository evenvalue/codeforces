#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  array<array<int, 4>, 2> ways{};
  ways[0][3] = 1;
  for (int i = 1, bit = 1; i <= n; i++, bit = 1 - bit) {
    for (const int j : {0, 1, 2, 3}) {
      ways[bit][j] = 0;
      for (const int k : {0, 1, 2, 3}) {
        if (k == j) continue;
        ways[bit][j] += ways[1 - bit][k];
        ways[bit][j] %= kMod;
      }
    }
  }
  cout << ways[n & 1][3];
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