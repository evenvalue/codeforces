#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<bool> t(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int work;
    cin >> work;
    t[i] = (work == 1);
    ans += t[i] ? a[i] : 0;
  }
  vector<int> dp(n - k + 1);
  for (int i = 0; i < k; i++) {
    if (not t[i]) {
      dp[0] += a[i];
    }
  }
  for (int i = 1; i < dp.size(); i++) {
    dp[i] = dp[i - 1];
    if (not t[i - 1]) {
      dp[i] -= a[i - 1];
    }
    if (not t[i + k - 1]) {
      dp[i] += a[i + k - 1];
    }
  }
  int extra = *max_element(dp.begin(), dp.end());
  cout << ans + extra << "\n";
}