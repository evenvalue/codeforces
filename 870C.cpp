#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    const int mod = n % 4;
    if (mod == 0) {
      cout << n / 4;
    } else if (mod == 1) {
      cout << ((n < 9) ? -2 : (n - 9) / 4) + 1;
    } else if (mod == 2) {
      cout << ((n < 6) ? -2 : (n - 6) / 4) + 1;
    } else {
      cout << ((n < 15) ? -3 : (n - 15) / 4) + 2;
    }
    cout << "\n";
  }
}