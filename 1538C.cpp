#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  int64 ans = 0;
  for (int i = 0; i < n; i++) {
    int atleast = n - (int)distance(a.begin(), lower_bound(a.begin(), a.end(), l - a[i]));
    int atmost = n - (int)distance(a.begin(), upper_bound(a.begin(), a.end(), r - a[i]));
    ans += atleast - atmost;
  }
  for (int i = 0; i < n; i++) {
    ans -= (l <= a[i] + a[i] and a[i] + a[i] <= r);
  }
  cout << ans / 2 << '\n';
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