#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int power(const int x, int k) {
  int ans = 1;
  while (k--) {
    ans = (ans * x) % mod;
  }
  return ans;
}

int32_t main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    if (c == 1) continue;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<bool> visit(n, false);
  function<int(int, int)> dfs = [&](int x, int p) {
    visit[x] = true;
    int sz = 1;
    for (int y : g[x]) {
      if (y == p) continue;
      sz += dfs(y, x);
    }
    return sz;
  };
  int ans = power(n, k);
  for (int i = 0; i < n; i++) {
    if (not visit[i]) {
      ans -= power(dfs(i, -1), k);
      ans += (ans < 0) ? mod : 0;
    }
  }
  cout << ans << "\n";
}