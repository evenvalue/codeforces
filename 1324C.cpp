#include <algorithm>
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
  vector<int> r = {-1};
  r.reserve(n + 2);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') continue;
    r.push_back(i);
  }
  r.push_back(n);
  int ans = 0;
  for (int i = 1; i < r.size(); i++) {
    ans = max(ans, r[i] - r[i - 1]);
  }
  cout << ans;
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