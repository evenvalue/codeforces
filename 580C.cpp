#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
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
  function<int(int, int, int)> dfs = [&](int x, int p, int streak) {
    streak += (a[x] == 1) ? 1 : -streak;
    if (streak > m) return 0;
    int ans = (x != 0 and g[x].size() == 1);
    for (int child : g[x]) {
      if (child == p) continue;
      ans += dfs(child, x, streak);
    }
    return ans;
  };
  cout << dfs(0, -1, 0) << "\n";
}