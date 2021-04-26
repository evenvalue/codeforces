#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  string s;
  cin >> k >> s;
  const int n = s.size();
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i - 1] - '0');
  }
  vector<int> cnt(n + 1);
  for (int i = 0; i <= n; i++) {
    cnt[pref[i]]++;
  }
  int64 ans = 0;
  for (int i = k; i <= n; i++) {
    if (k == 0) {
      ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    } else {
      ans += 1LL * cnt[i] * cnt[i - k];
    }
  }
  cout << ans << "\n";
}