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
  vector<int> a(n);
  for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  int64 dist = 0;
  for (int i = 1; i < n; i++) {
    dist += a[i] - a[0];
  }
  int ans = a[0];
  int64 mn_dist = dist;
  for (int i = 1; i < n; i++) {
    int64 happy = (int64)(n - i) * (a[i] - a[i - 1]);
    int64 sad = (int64)i * (a[i] - a[i - 1]);
    dist -= happy - sad;
    if (dist < mn_dist) {
      mn_dist = dist;
      ans = a[i];
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