#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vector<int> left(m), right(m);
  for (int i = 0, j = 0; i < n and j < m; i++) {
    if (s[i] == t[j]) {
      left[j] = i;
      j++;
    }
  }
  for (int i = n - 1, j = m - 1; i >= 0 and j >= 0; i--) {
    if (s[i] == t[j]) {
      right[j] = i;
      j--;
    }
  }
  int ans = 1;
  for (int i = 0; i + 1 < m; i++) {
    ans = max(ans, right[i + 1] - left[i]);
  }
  cout << ans << "\n";
}