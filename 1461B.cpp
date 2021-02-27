#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (vector<int> &row : grid) {
      for (int &cell : row) {
        char c;
        cin >> c;
        cell = (c == '*');
      }
    }
    vector<vector<int>> width(n, vector<int> (m));
    for (int r = 0; r < n; r++) {
      for (int c = 0, cnt = 0; c < m; c++) {
        cnt = (grid[r][c]) ? cnt + 1 : 0;
        width[r][c] = cnt;
      }
      for (int c = m - 1, cnt = 0; c >= 0; c--) {
        cnt = (grid[r][c]) ? cnt + 1 : 0;
        width[r][c] = min(width[r][c], cnt);
      }
    }
    int ans = 0;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        for (int rr = r; rr < n; rr++) {
          if (width[rr][c] <= rr - r) break;
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}