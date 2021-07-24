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
  vector<int> a(n);
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]].push_back(i);
  }
  vector<int> ans(n);
  vector<pair<int, int>> to_paint;
  to_paint.reserve(k);
  auto paint = [&]() {
    for (const auto &[i, c] : to_paint) {
      ans[i] = c;
    }
    to_paint.clear();
  };
  int mod = 0;
  auto check = [&]() {
    if (mod == 0) paint();
  };
  for (int i = 0; i < n; i++) {
    mod -= (mod > k ? k : 0);
    for (int j = 0; j < min((int)pos[i].size(), k); j++) {
      check();
      to_paint.emplace_back(pos[i][j], mod + 1);
      mod++;
      mod -= (mod >= k ? k : 0);
    }
  }
  check();
  for (const int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
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