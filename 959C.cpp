#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n < 6) {
    cout << -1 << "\n";
  } else {
    int x = (n - 1) / 2;
    for (int i = 2; i < 3 + x; i++) {
      cout << 1 << " " << i << "\n";
    }
    for (int i = 3 + x; i <= n; i++) {
      cout << 2 << " " << i << "\n";
    }
  }
  for (int i = 1; i < n; i++) {
    cout << i << " " << i + 1 << "\n";
  }
}