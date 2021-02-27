#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] != s[i - 1]) continue;
    ans++;
    if (s[i] != 'R' and s[i + 1] != 'R') s[i] = 'R';
    else if (s[i] != 'B' and s[i + 1] != 'B') s[i] = 'B';
    else s[i] = 'G';
  }
  if (n > 1 and s[n - 1] == s[n - 2]) {
    ans++;
    s[n - 1] = (s[n - 1] == 'R') ? 'B' : 'R';
  }
  cout << ans << "\n" << s << "\n";
}