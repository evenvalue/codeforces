#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int x, y, cost;
    cin >> x >> y >> cost;
    g[y - 1].push_back({cost, x - 1});
  }
  for (auto &x : g) {
    sort(x.begin(), x.end());
  }
  int cost = 0;
  for (int i = 0; i < n - 1; i++) {
    if (g[a[i].second].empty()) {
      cout << -1 << "\n";
      return 0;
    }
    cost += g[a[i].second][0].first;
  }
  cout << cost << "\n";
}