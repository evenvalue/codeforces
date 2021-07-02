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
  int n, m;
  cin >> n >> m;
  int lo = m, hi = m;
  int T = 0;
  bool satisfy = true;
  for (int i = 0; i < n; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if ((hi + (t - T)) < l or r < (lo - (t - T))) {
      satisfy = false;
    } else {
      lo = max(lo - (t - T), l);
      hi = min(hi + (t - T), r);
      T = t;
    }
  }
  cout << (satisfy ? "YES" : "NO");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}