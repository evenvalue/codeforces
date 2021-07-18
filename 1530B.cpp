#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> ans(n + 2, string(m + 2, '0'));
  ans[1][1] = '1';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i != 1 and i != n and j != 1 and j != m) continue;
      if (ans[i - 1][j] == '1' or ans[i][j - 1] == '1') continue;
      if (ans[i - 1][j - 1] == '1' or ans[i - 1][j + 1] == '1') continue;
      ans[i][j] = '1';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}