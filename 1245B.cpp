#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, r, p, s;
    string bob;
    cin >> n >> r >> p >> s >> bob;
    string alice;
    int ans = 0;
    for (char sign : bob) {
      if (sign == 'R' and p > 0) {
        alice += 'P';
        p--;
        ans++;
      } else if (sign == 'P' and s > 0) {
        alice += 'S';
        s--;
        ans++;
      } else if (sign == 'S' and r > 0) {
        alice += 'R';
        r--;
        ans++;
      } else {
        alice += '0';
      }
    }
    if (ans < (n + 1) / 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (char sign : alice) {
      if (sign == '0') {
        if (r > 0) {
          cout << 'R';
          r--;
        } else if (p > 0) {
          cout << 'P';
          p--;
        } else {
          cout << 'S';
          s--;
        }
        continue;
      }
      cout << sign;
    }
    cout << "\n";
  }
}