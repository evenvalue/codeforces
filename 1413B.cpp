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
  vector<pair<int, int>> num(n * m);
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      int x;
      cin >> x;
      x--;
      num[x].second = c;
    }
  }
  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      int x;
      cin >> x;
      x--;
      num[x].first = c;
    }
  }
  vector<vector<int>> ans(n, vector<int>(m));
  for (int x = 0; x < n * m; x++) {
    ans[num[x].first][num[x].second] = x;
  }
  for (const vector<int> &row : ans) {
    for (const int x : row) {
      cout << x + 1 << ' ';
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