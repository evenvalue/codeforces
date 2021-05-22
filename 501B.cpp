#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int dfs(const vector<vector<int>> &g, vector<bool> &visit, const int x) {
  visit[x] = true;
  if (g[x].empty()) {
    return x;
  }
  assert(g[x].size() == 1);
  return dfs(g, visit, g[x][0]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  struct var {
    int x = -1;
  };

  int n;
  cin >> n;
  map<string, var> idx;
  vector<string> back;
  back.reserve(2 * n);
  vector<vector<int>> g(2 * n);
  int last = -1;
  for (int i = 0; i < n; i++) {
    string prv, nxt;
    cin >> prv >> nxt;
    if (idx[prv].x == -1) {
      last++;
      idx[prv].x = last;
      back.push_back(prv);
    }
    last++;
    idx[nxt].x = last;
    back.push_back(nxt);
    int x = idx[prv].x;
    int y = idx[nxt].x;
    g[x].push_back(y);
  }
  vector<bool> visit(2 * n, false);
  vector<pair<int, int>> ans;
  ans.reserve(back.size());
  for (int x = 0; x < back.size(); x++) {
    if (visit[x]) continue;
    const int y = dfs(g, visit, x);
    ans.emplace_back(x, y);
  }
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << back[x] << ' ' << back[y] << '\n';
  }
  cout << '\n';
}