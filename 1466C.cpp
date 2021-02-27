#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    const int n = s.length();
    vector<bool> change(n, false);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (not change[i - 1] and s[i] == s[i - 1]) {
        change[i] = true;
      }
      if (i >= 2 and not change[i - 2] and s[i] == s[i - 2]) {
        change[i] = true;
      }
      ans += change[i];
    }
    cout << ans << "\n";
  }
}