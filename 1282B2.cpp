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
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    vector<int> dp(n, a[0]);
    for (int i = 1; i < k - 1; i++) {
      dp[i] = dp[i - 1] + a[i];
    }
    dp[k - 1] = a[k - 1];
    for (int i = k; i < n; i++) {
      dp[i] = dp[i - k] + a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] <= p) {
        ans = i + 1;
      }
    }
    cout << ans << "\n";
  }
}