#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int &x : w) {
      cin >> x;
    }
    vector<int> d(n, 0);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      d[x]++;
      d[y]++;
    }
    int ans = 0;
    vector<int> colour;
    for (int i = 0; i < n; i++) {
      ans += w[i];
      for (int j = 0; j < d[i] - 1; j++) {
        colour.push_back(w[i]);
      }
    }
    sort(colour.rbegin(), colour.rend());
    for (int c : colour) {
      cout << ans << " ";
      ans += c;
    }
    cout << ans << "\n";
  }
}