#include <algorithm>
#include <iostream>
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
    const int inf = (int)s.length() + 10;
    int a = -inf, b = -inf, c = -inf;
    int ans = inf;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        a = i;
      } else if (s[i] == '2') {
        b = i;
      } else if (s[i] == '3') {
        c = i;
      }
      ans = min(ans, max({a, b, c}) - min({a, b, c}) + 1);
    }
    if (a < 0 or b < 0 or c < 0) {
      cout << 0 << "\n";
      continue;
    }
    cout << ans << "\n";
  }
}