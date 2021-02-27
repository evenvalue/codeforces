#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  dp[1][0][0] = 2;
  dp[0][1][0] = 4;
  dp[0][0][1] = 8;
  for (int size = 2; size <= n; size++) {
    for (int b = 0; b <= size; b++) {
      for (int g = 0; g <= size - b; g++) {
        const int r = size - b - g;
        if (b > 1) dp[b][g][r] |= dp[b - 1][g][r];
        if (g > 1) dp[b][g][r] |= dp[b][g - 1][r];
        if (r > 1) dp[b][g][r] |= dp[b][g][r - 1];
        if (b > 0 and g > 0) dp[b][g][r] |= dp[b - 1][g - 1][r + 1];
        if (b > 0 and r > 0) dp[b][g][r] |= dp[b - 1][g + 1][r - 1];
        if (g > 0 and r > 0) dp[b][g][r] |= dp[b + 1][g - 1][r - 1];
      }
    }
  }
  string s;
  cin >> s;
  const int B = count(s.begin(), s.end(), 'B');
  const int G = count(s.begin(), s.end(), 'G');
  const int R = count(s.begin(), s.end(), 'R');
  if (dp[B][G][R] & 2) cout << 'B';
  if (dp[B][G][R] & 4) cout << 'G';
  if (dp[B][G][R] & 8) cout << 'R';
  cout << "\n";
}