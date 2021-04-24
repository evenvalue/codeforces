#include <algorithm>
#include <iostream>
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
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      pref[i] = pref[i - 1] + (c - '0') - 1;
    }
    sort(pref.begin(), pref.end());
    int old = 0, streak = 0;
    int64 ans = 0;
    for (const int x : pref) {
      streak = (x == old ? streak : 0);
      ans += streak;
      old = x;
      streak++;
    }
    cout << ans << "\n";
  }
}