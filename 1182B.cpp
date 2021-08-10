#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

bool empty(const char c) {
  return (c == '.');
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  int non_empty = 0;
  for (string &s : grid) {
    cin >> s;
    non_empty += count(s.begin(), s.end(), '*');
  }
  pair<int, int> middle = {-1, -1};
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (empty(grid[i][j])) continue;
      if (empty(grid[i - 1][j]) or empty(grid[i + 1][j]) or empty(grid[i][j - 1]) or empty(grid[i][j + 1])) continue;
      middle = {i, j};
    }
  }
  int cnt = 0;
  if (middle != make_pair(-1, -1)) {
    bool found = false;
    for (int r = middle.first, c = 0; c < m; c++) {
      if (not found and empty(grid[r][c])) continue;
      if (found and empty(grid[r][c])) break;
      found = true;
      cnt++;
    }
    found = false;
    for (int r = 0, c = middle.second; r < n; r++) {
      if (not found and empty(grid[r][c])) continue;
      if (found and empty(grid[r][c])) break;
      found = true;
      cnt++;
    }
  }
  cout << (middle != make_pair(-1, -1) and (cnt == non_empty + 1) ? "YES" : "NO") << '\n';
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