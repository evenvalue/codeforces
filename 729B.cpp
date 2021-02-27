#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> actor(n, vector<int>(m));
  for (vector<int> &row : actor) {
    for (int &cell : row) {
      cin >> cell;
    }
  }
  vector<pair<int, int>> row(n, {m + 10, -10});
  vector<pair<int, int>> col(m, {n + 10, -10});
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (actor[r][c]) {
        row[r].first = min(row[r].first, c);
        row[r].second = max(row[r].second, c);
        col[c].first = min(col[c].first, r);
        col[c].second = max(col[c].second, r);
      }
    }
  }
  int ans = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (not actor[r][c]) {
        ans += (c > row[r].first);
        ans += (c < row[r].second);
        ans += (r > col[c].first);
        ans += (r < col[c].second);
      }
    }
  }
  cout << ans << "\n";
}