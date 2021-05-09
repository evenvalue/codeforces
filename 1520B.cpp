#include <iostream>
#include <string>
using namespace std;

#define int int64_t

void solve() {
  int n;
  cin >> n;
  string s = to_string(n);
  bool ok = true;
  for (const char c : s) {
    if (s[0] < c) break;
    ok &= (s[0] == c);
  }
  int ans = 9 * (s.size() - 1);
  ans += (s[0] - '0') - 1;
  ans += ok;
  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}