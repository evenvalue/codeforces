#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int diameter(const vector<vector<int>> &g) {
  function<pair<int, int>(int, int, int)> dfs = [&](int x, int p, int level) {
    pair<int, int> max_dist = {level, x};
    for (int y : g[x]) {
      if (y == p) continue;
      max_dist = max(max_dist, dfs(y, x, level + 1));
    }
    return max_dist;
  };
  int far = dfs(0, -1, 0).second;
  return dfs(far, -1, 0).first;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << diameter(g) << "\n";
}