#include <iostream>
#include <string>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    const int n = s.length();
    s[n - 1] = 'C';
    int i = n - 1;
    for (int cost = 0; i > 0; i--) {
      if (s[i] != s[i - 1]) {
        cost += (s[i - 1] == 'A') ? a : b;
        if (cost > p) break;
      }
    }
    cout << i + 1 << "\n";
  }
}