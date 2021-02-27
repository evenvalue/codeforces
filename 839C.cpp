#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  g[0].push_back(-1);
  function<double(int, int)> dfs = [&](int x, int p) {
    if (g[x].size() == 1) return 0.0;
    double avg = 0;
    for (int y : g[x]) {
      if (y == p) continue;
      avg += dfs(y, x);
    }
    avg /= g[x].size() - 1;
    return avg + 1;
  };
  cout << fixed << setprecision(10) << dfs(0, -1) << "\n";
}