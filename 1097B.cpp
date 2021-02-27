#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  for (int i = 0; i < (1 << (n + 1)); i++) {
    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        ans += a[j];
      } else {
        ans -= a[j];
      }
    }
    if (ans % 360 == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}