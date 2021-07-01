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

int len(const string &s, int x, int y) {
  int ans = 0;
  for (const char c : s) {
    if (c - '0' != x) continue;
    ans++;
    swap(x, y);
  }
  ans -= (x != y and (ans & 1));
  return ans;
}

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      ans = max(ans, len(s, x, y));
    }
  }
  cout << s.size() - ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}