#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <fstream>
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

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(const int TestCase) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> grid(n);
  for (string &row : grid) cin >> row;
  for (int c = 0; c < m; c++) {
    int ans = 0;
    for (int r = 0; r < n; r++) {
      ans += (c >= r and grid[r][c - r] == 'R');
      ans += (c + r < m and grid[r][r + c] == 'L');
      ans += (r + r < n and grid[r + r][c] == 'U');
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }
}