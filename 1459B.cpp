#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  const int k = n / 2;
  if (n % 2 == 0) {
    cout << (k + 1) * (k + 1);
  } else {
    cout << 2 * (k + 1) * (k + 2);
  }
}