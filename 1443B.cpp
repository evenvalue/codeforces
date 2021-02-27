#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    const int n = s.length();
    const int first_bomb = distance(s.begin(), find(s.begin(), s.end(), '1'));
    if (first_bomb == n) {
      cout << 0 << "\n";
      continue;
    }
    int ans = a;
    int left = first_bomb;
    for (int i = first_bomb + 1; i < n; i++) {
      if (s[i] == '1') {
        int streak = i - left - 1;
        ans += (streak * b < a) ? streak * b : a;
        left = i;
      }
    }
    cout << ans << "\n";
  }
}