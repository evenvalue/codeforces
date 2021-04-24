#include <iostream>
#include <vector>
#include <map>
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
      pref[i] = pref[i - 1] + (c - '0' - 1);
    }
    map<int, int> freq;
    for (int i = 0; i <= n; i++) {
      freq[pref[i]]++;
    }
    int64 ans = 0;
    for (const pair<int, int> p : freq) {
      const int x = p.second;
      ans += 1LL * x * (x - 1) / 2;
    }
    cout << ans << "\n";
  }
}