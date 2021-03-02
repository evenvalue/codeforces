#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> block(k, vector<int>(26));
    for (int i = 0; i < n; i++) {
      block[i % k][s[i] - 'a']++;
    }
    int ans = 0;
    for (int x = 0, y = k - 1; x < y; x++, y--) {
      int mx = 0;
      for (int j = 0; j < 26; j++) {
        mx = max(mx, block[x][j] + block[y][j]);
      }
      ans += accumulate(block[x].begin(), block[x].end(), 0);
      ans += accumulate(block[y].begin(), block[y].end(), 0);
      ans -= mx;
    }
    if (k % 2 == 1) {
      const int mid = k / 2;
      ans += accumulate(block[mid].begin(), block[mid].end(), 0);
      ans -= *max_element(block[mid].begin(), block[mid].end());
    }
    cout << ans << "\n";
  }
}