#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coordinate {
  int x, y;
};

coordinate up(const coordinate &c) {
  return {c.x - 1, c.y};
}

coordinate down(const coordinate &c) {
  return {c.x + 1, c.y};
}

coordinate left(const coordinate &c) {
  return {c.x, c.y - 1};
}

coordinate right(const coordinate &c) {
  return {c.x, c.y + 1};
}

bool solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> grid(n + 2, vector<bool>(m + 2, false));
  vector<coordinate> good;
  vector<coordinate> bad;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      char c;
      cin >> c;
      grid[x][y] = (c != '#');
      if (c == 'G') good.push_back({x, y});
      if (c == 'B') bad.push_back({x, y});
    }
  }
  for (const coordinate &b : bad) {
    grid[up(b).x][up(b).y] = false;
    grid[down(b).x][down(b).y] = false;
    grid[left(b).x][left(b).y] = false;
    grid[right(b).x][right(b).y] = false;
  }
  vector<vector<bool>> visit(n + 2, vector<bool>(m + 2, false));
  auto bfs = [&]() -> void {
    queue<coordinate> q;
    q.push({n, m});
    while (not q.empty()) {
      const coordinate c = q.front();
      q.pop();
      if (not grid[c.x][c.y] or visit[c.x][c.y]) continue;
      visit[c.x][c.y] = true;
      q.push(up(c));
      q.push(down(c));
      q.push(left(c));
      q.push(right(c));
    }
  };
  bfs();
  bool escaped = true;
  for (const coordinate &g : good) {
    escaped &= visit[g.x][g.y];
  }
  return escaped;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}