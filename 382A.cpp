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
  string s, add;
  cin >> s >> add;
  string side1 = s.substr(0, s.find('|'));
  string side2 = s.substr(side1.size() + 1);
  for (const char c : add) {
    if (side1.size() <= side2.size()) {
      side1 += c;
    } else {
      side2 += c;
    }
  }
  cout << (side1.size() != side2.size() ? "Impossible" : side1 + '|' + side2) << '\n';
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