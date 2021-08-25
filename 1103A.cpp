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

void solve() {
  string s;
  cin >> s;
  bool horizontal = false;
  bool vertical = false;
  for (const char c : s) {
    if (c == '0') {
      if (vertical) {
        cout << 1 << ' ' << 1;
      } else {
        cout << 3 << ' ' << 1;
      }
      vertical = not vertical;
    } else {
      if (horizontal) {
        cout << 1 << ' ' << 1;
      } else {
        cout << 1 << ' ' << 3;
      }
      horizontal = not horizontal;
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