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
  int n;
  cin >> n;
  vector<int64> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<int64> pref(n + 1), suff(n + 2);
  for (int i = 1, j = n; i <= n and j >= 0; i++, j--) {
    pref[i] = pref[i - 1] + (a[i] * b[i]);
    suff[j] = suff[j + 1] + (a[j] * b[j]);
  }
  vector<vector<int64>> best(n + 1, vector<int64>(n + 1));
  for (int i = 1; i <= n; i++) {
    best[i][i] = (a[i] * b[i]);
  }
  for (int l = n; l >= 1; l--) {
    for (int r = l + 1; r <= n; r++) {
      best[l][r] = best[l + 1][r - 1] + (a[l] * b[r]) + (a[r] * b[l]);
    }
  }
  int64 ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      ans = max(ans, pref[l - 1] + best[l][r] + suff[r + 1]);
    }
  }
  cout << ans << '\n';
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