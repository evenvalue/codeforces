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

int solve(const string &s, const char c, const int k) {
  const int n = s.size();
  int res = 0, invert = 0;
  int l = -1, r = -1;
  while (l < n and r < n - 1) {
    if (s[r + 1] == c or invert + 1 <= k) {
      r++;
      invert += (s[r] != c);
      res = max(res, r - l);
    } else {
      l++;
      invert -= (s[l] != c);
    }
  }
  return res;
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  cout << max(solve(s, 'a', k), solve(s, 'b', k));
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