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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (string &row : grid) {
    cin >> row;
  }
  bool way1 = false, way2 = false;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      const bool odd = (r + c) & 1;
      if ((odd and (grid[r][c] == 'W')) or (not odd and (grid[r][c] == 'R'))) {
        way1 = true;
      } else if (grid[r][c] != '.') {
        way2 = true;
      }
    }
  }
  if (way1 and way2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (way1) {
        cout << ((r + c) & 1 ? 'W' : 'R');
      } else {
        cout << ((r + c) & 1 ? 'R' : 'W');
      }
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}