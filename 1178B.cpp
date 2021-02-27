#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  const int n = s.length();
  vector<int> p(n, 0);
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + (s[i] == 'v' and s[i - 1] == 'v');
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      ans += p[i] * (p[n - 1] - p[i]);
    }
  }
  cout << ans << "\n";
}