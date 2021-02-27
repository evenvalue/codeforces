#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2));
  dp[n - 1][0] = {a[n - 1], 0};
  dp[n - 1][1] = {0, a[n - 1]};
  for (int i = n - 2; i >= 0; i--) {
    const pair<int, int> turn_a = {dp[i + 1][0].first, dp[i + 1][0].second + a[i]};
    const pair<int, int> turn_b = {dp[i + 1][1].first + a[i], dp[i + 1][1].second};
    dp[i][0] = max(turn_a, turn_b);
    dp[i][1] = max(turn_a, turn_b, [](const pair<int, int> p1, const pair<int, int> p2) {
      return p1.first > p2.first;
    });
  }
  cout << dp[0][1].first << " " << dp[0][1].second << "\n";
}