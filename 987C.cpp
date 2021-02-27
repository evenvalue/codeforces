#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int inf = 1e9 + 10;
  int n;
  cin >> n;
  vector<int> s(n);
  vector<int> c(n);
  for (int &size : s) {
    cin >> size;
  }
  for (int &cost : c) {
    cin >> cost;
  }
  vector<int> dp(n, inf);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] < s[j]) {
        dp[i] = min(dp[i], c[i] + c[j]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] < s[j]) {
        ans = min(ans, c[i] + dp[j]);
      }
    }
  }
  cout << (ans == inf ? -1 : ans) << "\n";
}