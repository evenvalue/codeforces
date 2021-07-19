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

vector<int> solve() {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (vector<int> &row : mat) {
    for (int &cell : row) {
      cin >> cell;
    }
  }
  if (n == 1) {
    return {1};
  }
  if (n == 2) {
    return {1, mat[0][1]};
  }
  vector<int> a(n);
  a[0] = sqrt((int64) mat[0][1] * mat[0][2] / mat[1][2]);
  a[1] = sqrt((int64) mat[1][0] * mat[1][2] / mat[0][2]);
  for (int i = 2; i < n; i++) {
    a[i] = sqrt((int64) mat[i][0] * mat[i][1] / mat[0][1]);
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    vector<int> a = solve();
    for (const int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}