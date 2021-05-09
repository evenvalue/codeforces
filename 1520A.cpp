#include <iostream>
#include <string>
using namespace std;

#define int int64_t

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool done[26];
  for (bool &x : done) {
    x = false;
  }
  done[s[0] - 'A'] = true;
  bool sus = false;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) continue;
    if (done[s[i] - 'A']) {
      sus = true;
      break;
    }
    done[s[i] - 'A'] = true;
  }
  cout << (sus ? "NO" : "YES") << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}