#include <algorithm>
#include <array>
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
  int n, k;
  cin >> n >> k;
  if (k > n * n) {
    cout << -1 << '\n';
    return;
  }
  vector<string> mat(n, string(n, '0'));
  for (int diagonal = 0; diagonal < n; diagonal++) {
    if (k == 0) break;
    mat[diagonal][diagonal] = '1';
    k--;
    for (int r = diagonal + 1, c = diagonal + 1; r < n and c < n; r++, c++) {
      if (k <= 1) break;
      mat[r][diagonal] = mat[diagonal][c] = '1';
      k -= 2;
    }
  }
  for (const string &s : mat) {
    for (const char c : s) {
      cout << c << ' ';
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