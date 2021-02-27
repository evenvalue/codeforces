#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int peak = a[0], ans = a[0];
    for (int i = 1; i < n; i++) {
      const bool same_sign = (a[i] * a[i - 1] > 0);
      if (same_sign) {
        if (a[i] > peak) {
          ans -= peak;
          peak = a[i];
          ans += peak;
        }
      } else {
        peak = a[i];
        ans += peak;
      }
    }
    cout << ans << "\n";
  }
}