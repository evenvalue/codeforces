#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> level(n, 0);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[x - 1].push_back(i);
  }
  function<void(int, int)> dfs = [&](int x, int l) {
    for (int y : g[x]) {
      dfs(y, l + 1);
    }
    level[l] = 1 - level[l];
  };
  dfs(0, 0);
  int ans = 0;
  for (int l : level) {
    ans += l;
  }
  cout << ans << "\n";
}