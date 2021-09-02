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
  int n;
  cin >> n;
  const pair<int, int> mid = {n / 2, n / 2};
  function<int(int, int)> dist = [&](const int r, const int c) {
    return abs(r - mid.first) + abs(c - mid.second);
  };
  int odd = -1, even = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cout << (dist(r, c) <= (n / 2) ? (odd += 2) : (even += 2)) << ' ';
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
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);  
  }
}