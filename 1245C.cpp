#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  const int mod = 1e9 + 7;
  string s;
  cin >> s;
  if (any_of(s.cbegin(), s.cend(), [&](const char c) {
        return (c == 'm' or c == 'w');
      })) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> fib(1e5 + 10, 1);
  for (int i = 2; i < fib.size(); i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fib[i] -= fib[i] > mod ? mod : 0;
  }
  s.push_back('a');
  int ans = 1;
  for (int i = 0, streak = 0; i < s.size(); i++) {
    if (s[i] != 'n' and s[i] != 'u') continue;
    streak++;
    if (s[i] != s[i + 1]) {
      ans *= fib[streak];
      ans %= mod;
      streak = 0;
    }
  }
  cout << ans << "\n";
}