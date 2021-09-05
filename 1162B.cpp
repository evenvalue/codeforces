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

bool increasing(const vector<vector<int>> &mat) {
  const int n = mat.size();
  const int m = mat[0].size();
  bool inc = true;
  for (int r = 0; r < n; r++) {
    for (int c = 1; c < m; c++) {
      inc &= (mat[r][c] > mat[r][c - 1]);
    }
  }
  for (int r = 1; r < n; r++) {
    for (int c = 0; c < m; c++) {
      inc &= (mat[r][c] > mat[r - 1][c]);
    }
  }
  return inc;
}

void solve(const int TestCase) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  for (vector<int> &row : a) {
    for (int &x : row) cin >> x;
  }
  vector<vector<int>> b(n, vector<int> (m));
  for (vector<int> &row : b) {
    for (int &x : row) cin >> x;
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (a[r][c] > b[r][c]) swap(a[r][c], b[r][c]);
    }
  }
  cout << (increasing(a) and increasing(b) ? "Possible" : "Impossible") << '\n';
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