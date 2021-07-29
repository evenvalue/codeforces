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

int64 nC2(const int n) {
  return (int64)n * (n - 1) / 2;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> men(n);
  for (pair<int, int> &man : men) {
    cin >> man.first >> man.second;
  }
  men.emplace_back(-kInf, -kInf);
  sort(men.begin(), men.end());
  int64 ans = 0;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (men[i].first != men[i - 1].first) ans += nC2(cnt);
    cnt = (men[i].first == men[i - 1].first ? cnt + 1 : 1);
  }
  ans += nC2(cnt);
  sort(men.begin(), men.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
    return make_pair(x.second, x.first) < make_pair(y.second, y.first);
  });
  cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (men[i].second != men[i - 1].second) ans += nC2(cnt);
    cnt = (men[i].second == men[i - 1].second ? cnt + 1 : 1);
  }
  ans += nC2(cnt);
  cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (men[i] != men[i - 1]) ans -= nC2(cnt);
    cnt = (men[i] == men[i - 1] ? cnt + 1 : 1);
  }
  cout << ans - nC2(cnt) << '\n';
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