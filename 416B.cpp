#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (vector<int> &pic : a) {
    for (int &painting_time : pic) {
      cin >> painting_time;
    }
  }
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = a[0][0];
  for (int pic = 1; pic < n; pic++) {
    dp[pic][0] = dp[pic - 1][0] + a[pic][0];
  }
  for (int paint = 1; paint < m; paint++) {
    dp[0][paint] = dp[0][paint - 1] + a[0][paint];
  }
  for (int pic = 1; pic < n; pic++) {
    for (int paint = 1; paint < m; paint++) {
      dp[pic][paint] = a[pic][paint] + max(dp[pic - 1][paint], dp[pic][paint - 1]);
    }
  }
  for (int pic = 0; pic < n; pic++) {
    cout << dp[pic][m - 1] << " ";
  }
}