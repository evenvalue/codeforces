#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  struct node {
    int64 l = 0;
    int64 r = 0;
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<node> v(n);
    for (node &vertex : v) {
      cin >> vertex.l >> vertex.r;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<node> dp(n);
    function<void(int, int)> dfs = [&](const int x, const int p) {
      for (const int y : g[x]) {
        if (y == p) continue;
        dfs(y, x);
        dp[x].l += max(dp[y].l + abs(v[x].l - v[y].l), dp[y].r + abs(v[x].l - v[y].r));
        dp[x].r += max(dp[y].l + abs(v[x].r - v[y].l), dp[y].r + abs(v[x].r - v[y].r));
      }
    };
    dfs(0, -1);
    cout << max(dp[0].l, dp[0].r) << '\n';
  }
}