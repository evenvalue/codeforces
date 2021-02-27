#include <iostream>
#include <string>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int ans = (s[0] % 4 == 0);
  for (int i = 1; i < s.length(); i++) {
    int cur = s[i] - '0';
    ans += (cur % 4 == 0);
    cur += 10 * (s[i - 1] - '0');
    ans += (cur % 4 == 0) ? i : 0;
  }
  cout << ans << "\n";
}