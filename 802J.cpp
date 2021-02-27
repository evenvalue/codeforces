#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<vector<pair<int, int>>> &g, int x, int p) {
  int dist = 0;
  for (const pair<int, int> &y : g[x]) {
    if (y.first == p) continue;
    dist = max(dist, y.second + dfs(g, y.first, x));
  }
  return dist;
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  cout << dfs(g, 0, -1) << "\n";
}