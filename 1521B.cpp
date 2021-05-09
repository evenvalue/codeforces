#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  const int mn = distance(a.begin(), min_element(a.begin(), a.end()));
  cout << n - 1 << "\n";
  int change = a[mn] + 1;
  for (int i = mn + 1; i < n; i++, change++) {
    cout << mn + 1 << " " << i + 1 << " ";
    cout << a[mn] << " " << change << "\n";
  }
  change = a[mn] + 1;
  for (int i = mn - 1; i >= 0; i--, change++) {
    cout << mn + 1 << " " << i + 1 << " ";
    cout << a[mn] << " " << change << "\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}