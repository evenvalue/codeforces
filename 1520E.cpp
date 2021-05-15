#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (s[i - 1] == '*');
    }
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') continue;
      ans += min(pref[i + 1], pref[n] - pref[i]);
    }
    cout << ans << "\n";
  }
}