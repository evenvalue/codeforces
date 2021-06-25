#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n';

bool push(pair<int, int> &p, const int insert) {
  if (p.second != -1) return false;
  if (p.first == -1) p.first = insert;
  else
    p.second = insert;
  return true;
}

bool dfs(const vector<vector<pair<int, int>>> &g, vector<bool> &visit, vector<int> &allot, int x) {
  visit[x] = true;
  bool ret = true;
  for (const auto [y, type] : g[x]) {
    if (visit[y] and (allot[y] ^ allot[x]) != type) return false;
    if (visit[y]) continue;
    allot[y] = allot[x] ^ type;
    ret &= dfs(g, visit, allot, y);
  }
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  for (int &x : r) {
    cin >> x;
  }
  vector<pair<int, int>> s(n, {-1, -1});
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    while (x--) {
      int door;
      cin >> door;
      assert(push(s[door - 1], i));
    }
  }
  vector<vector<pair<int, int>>> g(m);
  for (int door = 0; door < n; door++) {
    g[s[door].first].push_back({s[door].second, 1 - r[door]});
    g[s[door].second].push_back({s[door].first, 1 - r[door]});
  }
  vector<bool> visit(m, false);
  vector<int> allot(m);
  bool yes = true;
  for (int x = 0; x < m; x++) {
    if (visit[x]) continue;
    yes &= dfs(g, visit, allot, x);
  }
  cout << (yes ? "YES" : "NO") << '\n';
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