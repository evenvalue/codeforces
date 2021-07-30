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
  for (int &x : a) {
    cin >> x;
  }
  vector<int> cnt(1e6 + 1);
  int distinct = 0;
  pair<int, int> ans = {-1, 0};
  auto update = [&ans](const int l, const int r) {
    if (r - l > ans.second - ans.first) {
      ans = {l, r};
    }
  };
  int l = -1, r = -1;
  while (r < n - 1) {
    if ((cnt[a[r + 1]] == 0 and distinct < k) or (cnt[a[r + 1]] != 0 and distinct <= k)) {
      r++;
      distinct += (cnt[a[r]] == 0);
      cnt[a[r]]++;
    } else {
      l++;
      cnt[a[l]]--;
      distinct -= (cnt[a[l]] == 0);
    }
    update(l, r);
  }
  cout << ans.first + 2 << ' ' << ans.second + 1 << '\n';
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