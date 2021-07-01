#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  const int n = s.size();
  string ans = "/";
  for (int i = 1; i < n; i++) {
    if (s[i] == '/' and s[i] == s[i - 1]) continue;
    ans += s[i];
  }
  if (ans.size() > 1 and ans.back() == '/') ans.pop_back();
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}