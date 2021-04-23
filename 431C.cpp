#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int kMod = 1e9 + 7;

int solve(const int sum, const int numbers) {
  vector<int> dp(sum + 1);
  dp[0] = 1;
  for (int x = 1; x <= sum; x++) {
    for (int num = 1; num <= min(x, numbers); num++) {
      dp[x] += dp[x - num];
      dp[x] %= kMod;
    }
  }
  return dp[sum];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k, d;
  cin >> n >> k >> d;
  cout << (solve(n, k) - solve(n, d - 1) + kMod) % kMod << "\n";
}