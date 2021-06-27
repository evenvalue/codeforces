#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

int dfs(const vector<vector<int>> &g, const int x, const int level) {
  int l = level;
  for (const int y : g[x]) {
    l = max(l, dfs(g, y, level + 1));
  }
  return l;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] == -1) continue;
    g[p[i] - 1].push_back(i);
  }
  int ans = 0;
  for (int x = 0; x < n; x++) {
    if (p[x] != -1) continue;
    ans = max(ans, dfs(g, x, 1));
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}