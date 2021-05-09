#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
    x--;
  }
  vector<int> freq(n);
  for (int i = 0; i < n; i++) {
    freq[i] = a[i] - i;
  }
  sort(freq.begin(), freq.end());
  int cnt = 1;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    cnt = (freq[i] == freq[i - 1] ? cnt + 1 : 1);
    ans += cnt - 1;
  }
  cout << ans << "\n";
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