#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kInf = 1e9 + 10;

  int query;
  cin >> query;
  while (query--) {
    string s;
    cin >> s;
    const int n = s.size();
    vector<vector<int>> pos(n, vector<int>(26, kInf));
    //pos[i][j] -> The first occurrence of j in s[i...n - 1]. if no such j exists in s[i...n - 1], then pos[i][j] = kInf.
    pos[n - 1][s[n - 1] - 'a'] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      for (int alpha = 0; alpha < 26; alpha++) {
        pos[i][alpha] = (s[i] == ('a' + alpha) ? i : pos[i + 1][alpha]);
      }
    }
    string t;
    cin >> t;
    int prev = -1;
    int ans = 1;
    for (char c : t) {
      if (pos[0][c - 'a'] == kInf) {
        ans = -1;
        break;
      }
      ans += (prev == n - 1 or pos[prev + 1][c - 'a'] == kInf);
      prev = ((prev != n - 1 and pos[prev + 1][c - 'a'] != kInf) ? pos[prev + 1][c - 'a'] : pos[0][c - 'a']);
    }
    cout << ans << "\n";
  }
}