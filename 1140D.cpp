#include <iostream>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 2; i < n; i++) {
    ans += i * (i + 1);
  }
  cout << ans << "\n";
}