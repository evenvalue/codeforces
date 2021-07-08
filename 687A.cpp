#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

struct edge {
  int x, y;
};

void solve() {
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
  vector<int> assign(n, -1);
  function<bool(int)> dfs = [&](const int x) {
    bool ret = true;
    for (const int y : g[x]) {
      if (assign[y] != -1 and assign[y] == 1 - assign[x]) continue;
      if (assign[y] != -1) return false;
      assign[y] = 1 - assign[x];
      ret &= dfs(y);
    }
    return ret;
  };
  for (int x = 0; x < n; x++) {
    if (assign[x] != -1) continue;
    assign[x] = 0;
    if (not dfs(x)) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << count(assign.begin(), assign.end(), 0) << '\n';
  for (int i = 0; i < n; i++) {
    if (assign[i] == 0) cout << i + 1 << ' ';
  }
  cout << '\n';
  cout << count(assign.begin(), assign.end(), 1) << '\n';
  for (int i = 0; i < n; i++) {
    if (assign[i] == 1) cout << i + 1 << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}