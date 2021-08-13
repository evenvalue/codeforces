#include <algorithm>
#include <map>
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

pair<int, int> sum(const pair<int, int> &x, const pair<int, int> &y) {
  return {x.first + y.first, x.second + y.second};
}

int diff(const pair<int, int> &x, const pair<int, int> &y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

void solve(map<char, pair<int, int>> &change) {
  string dir;
  cin >> dir;
  const int n = dir.length();
  vector<pair<int, int>> pos(n + 1, {0, 0});
  for (int i = 1; i <= n; i++) {
    pos[i] = sum(pos[i - 1], change[dir[i - 1]]);
  }
  bool ans = true;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 2; j <= n; j++) {
      ans &= diff(pos[i], pos[j]) > 1;
    }
  }
  cout << (ans ? "OK" : "BUG") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<char, pair<int, int>> change;
  change['L'] = {-1, 0};
  change['R'] = {1, 0};
  change['U'] = {0, 1};
  change['D'] = {0, -1};

  int t = 1;
  //cin >> t;
  while (t--) {
    solve(change);
  }
}