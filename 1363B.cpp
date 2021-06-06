#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    const int n = s.size();
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }
    int ans = 1e9 + 10;
    for (int cut = 0; cut <= n; cut++) {
      const int l1 = pref[cut], l0 = cut - l1;
      const int r1 = pref[n] - pref[cut], r0 = n - cut - r1;
      ans = min(ans, l1 + r0);
      ans = min(ans, l0 + r1);
    }
    cout << ans << '\n';
  }
}