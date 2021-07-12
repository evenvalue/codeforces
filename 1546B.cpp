#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v(2 * n - 1);
  for (string &s : v) cin >> s;
  vector<vector<int>> occ(m, vector<int>(26));
  for (const string &s : v) {
    for (int i = 0; i < m; i++) {
      occ[i][s[i] - 'a']++;
    }
  }
  string ans;
  for (const vector<int> &letters : occ) {
    for (int alpha = 0; alpha < 26; alpha++) {
      if (letters[alpha] & 1) {
        ans += (char)('a' + alpha);
        break;
      }
    }
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