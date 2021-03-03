#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, up, rt, dn, lf;
    cin >> n >> up >> rt >> dn >> lf;
    bool possible = false;
    for (int mask = 0; mask < 16; mask++) {
      const int tl = mask >> 0 & 1;
      const int tr = mask >> 1 & 1;
      const int bl = mask >> 2 & 1;
      const int br = mask >> 3 & 1;
      const bool u = 0 <= (up - tl - tr) and (up - tl - tr) <= n - 2;
      const bool r = 0 <= (rt - tr - br) and (rt - tr - br) <= n - 2;
      const bool d = 0 <= (dn - bl - br) and (dn - bl - br) <= n - 2;
      const bool l = 0 <= (lf - tl - bl) and (lf - tl - bl) <= n - 2;
      possible |= u and r and d and l;
    }
    cout << (possible ? "YES" : "NO") << "\n";
  }
}