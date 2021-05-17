#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void accept(const int x) {
  cout << "YES\n" << x + 1 << "\n";
  exit(0);
}

void reject() {
  cout << "NO\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> c(n);
  for (int &node : c) {
    cin >> node;
  }

  function<pair<int, int>(int, int)> dfs1 = [&](const int x, const int p) {
    for (const int y : g[x]) {
      if (y == p) continue;
      if (c[x] != c[y]) return make_pair(x, y);
      pair<int, int> edge = dfs1(y, x);
      if (edge != make_pair(-1, -1)) return edge;
    }
    return make_pair(-1, -1);
  };

  function<bool(int, int)> dfs2 = [&g, &c, &dfs2](const int x, const int p) {
    bool ret = true;
    for (const int y : g[x]) {
      if (y == p) continue;
      ret &= (dfs2(y, x) and ((c[x] == c[y]) or (p == -1)));
    }
    return ret;
  };

  auto [x, y] = dfs1(0, -1);
  if (x == -1 or y == -1) accept(0);
  if (dfs2(x, -1)) accept(x);
  if (dfs2(y, -1)) accept(y);
  reject();
}