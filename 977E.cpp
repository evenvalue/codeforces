#include <iostream>
#include <vector>
using namespace std;

bool check_cycle(const vector<vector<int>> &g, vector<bool> &visit, int x) {
  visit[x] = true;
  bool cycle = (g[x].size() == 2);
  for (const int y : g[x]) {
    if (visit[y]) continue;
    cycle &= check_cycle(g, visit, y);
  }
  return cycle;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<bool> visit(n, false);
  int ans = 0;
  for (int x = 0; x < n; x++) {
    if (not visit[x]) {
      ans += check_cycle(g, visit, x);
    }
  }
  cout << ans << '\n';
}
