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
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  vector<pair<int, int>> ways;
  for (int vasya = a; vasya <= x; vasya++) {
    for (int petya = b; petya < min(y + 1, vasya); petya++) {
      ways.emplace_back(vasya, petya);
    }
  }
  cout << ways.size() << '\n';
  for (const auto &[vasya, petya] : ways) {
    cout << vasya << ' ' << petya << '\n';
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