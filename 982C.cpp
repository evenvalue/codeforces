#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << -1 << "\n";
    return 0;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  function<int(int, int)> dfs = [&](int x, int p) {
    int sz = 1;
    for (int y : g[x]) {
      if (y == p) continue;
      sz += dfs(y, x);
    }
    if (sz % 2 == 0) ans++;
    return sz;
  };
  dfs(0, -1);
  cout << ans - 1 << "\n";
}