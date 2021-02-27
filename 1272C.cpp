#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<bool> key(26);
  while (k--) {
    char c;
    cin >> c;
    key[c - 'a'] = true;
  }
  int ans = 0;
  for (int i = 0, cur = 0; i < n; i++) {
    if (key[s[i] - 'a']) {
      cur++;
      ans += cur;
    } else {
      cur = 0;
    }
  }
  cout << ans << "\n";
}