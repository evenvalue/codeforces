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

void solve() {
  int n, m;
  cin >> n >> m;
  if (n == 1 and m == 1) {
    cout << 0 << '\n';
    return;
  }
  if (m == 1) {
    for (int i = 2; i <= n + 1; i++) {
      cout << i << '\n';
    }
    return;
  }
  vector<vector<int>> a(n, vector<int>(m));
  iota(a[0].begin(), a[0].end(), 2);
  int target = m + 1;
  for (int r = 1; r < n; r++) {
    target++;
    for (int c = 0; c < m; c++) {
      a[r][c] = (c + 2) * target;
    }
  }
  for (const vector<int> &row : a) {
    for (const int cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
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
  }
}