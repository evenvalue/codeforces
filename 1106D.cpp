#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

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
  vector<int> ans;
  ans.reserve(n);
  vector<bool> visit(n, false);
  set<int> q;
  q.insert(0);
  while (not q.empty()) {
    const int x = *q.begin();
    q.erase(q.begin());
    visit[x] = true;
    for (const int y : g[x]) {
      if (visit[y]) continue;
      q.insert(y);
    }
    ans.push_back(x);
  }
  for (const int x : ans) {
    cout << x + 1 << ' ';
  }
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