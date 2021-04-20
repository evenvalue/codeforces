#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kMaxN = 1e5;

  int n;
  cin >> n;
  vector<int64> a(kMaxN + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] += x;
  }
  vector<int64> dp(kMaxN + 2);
  dp[kMaxN] = a[kMaxN];
  for (int x = kMaxN - 1; x > 0; x--) {
    dp[x] = max(dp[x + 1], a[x] + dp[x + 2]);
  }
  cout << dp[1];
}