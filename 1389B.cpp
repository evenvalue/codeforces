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
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    vector<vector<int>> dp(k + 1, vector<int>(z + 1));
    dp[0][0] = a[0];
    for (int r = 1; r <= k; r++) {
      for (int l = 0; l <= min(r, z) and r + l <= k; l++) {
        dp[r][l] = (l == 0 ? 0 : dp[r][l - 1]) + a[r - l];
        dp[r][l] = max(dp[r][l], dp[r - 1][l] + a[r - l]);
      }
    }
    int ans = 0;
    for (int l = 0; l <= z; l++) {
      ans = max(ans, dp[k - l][l]);
    }
    cout << ans << "\n";
  }
}