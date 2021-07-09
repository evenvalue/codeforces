#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int64 ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i] and a[i] > a[i + 1]) {
      ans -= a[i] - max(a[i - 1], a[i + 1]);
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}