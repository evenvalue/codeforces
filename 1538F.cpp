#include <iostream>
using namespace std;

#define int64 int64_t

int64 solve(const int x) {
  int64 ans = 0;
  for (int64 place = 1; place <= x; place *= 10) {
    ans += x / place;
  }
  return ans;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l) << '\n';
  }
}