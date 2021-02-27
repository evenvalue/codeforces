#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(42);
  while (q--) {
    char a1, a2, b;
    cin >> a1 >> a2 >> b;
    int x = (6 * (a1 - 'a' + 1)) + (a2 - 'a' + 1) - 1;
    g[b - 'a'].push_back(x);
    g[x].push_back(a1 - 'a');
  }
  int ans = 0;
  function<void(int, int)> dfs = [&](int x, int len) {
    if (len == n) {
      ans++;
      return;
    }
    for (int &y : g[x]) {
      dfs(y, len + (y > 5));
    }
  };
  dfs(0, 1);
  cout << ans << "\n";
}