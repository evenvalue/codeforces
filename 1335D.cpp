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
  array<string, 9> sudoku;
  for (string &row : sudoku) {
    cin >> row;
  }
  for (string &row : sudoku) {
    for (char &cell : row) {
      if (cell != '2') continue;
      cell = '1';
    }
  }
  for (const string &row : sudoku) {
    cout << row << '\n';
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