#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int &x : a) {
      cin >> x;
      ans += (x <= 0);
    }
    sort(a.begin(), a.end());
    int diff = 1e9 + 100;
    for (int i = 1; i < n; i++) {
      if (a[i] <= 0) {
        diff = min(diff, a[i] - a[i - 1]);
      }
    }
    for (int i = n - 1; i >= 0 and a[i] > 0; i--) {
      if (a[i] > diff) continue;
      ans++;
      break;
    }
    cout << ans << '\n';
  }
}