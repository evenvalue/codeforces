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
  cout << (n & 1 ? 1 + ((n - 3) / 2) : (n / 2)) << '\n';
  if (n & 1) {
    cout << 3 << ' ';
    n -= 3;
  }
  while (n) {
    cout << 2 << ' ';
    n -= 2;
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
    cout << '\n';
  }
}