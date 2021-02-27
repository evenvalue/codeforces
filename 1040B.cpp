#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  cout << (n + (2 * k)) / ((2 * k) + 1) << "\n";
  int flip = (n % (2 * k + 1) > k or n % (2 * k + 1) == 0) ? k + 1 : 1;
  cout << flip << " ";
  while (flip + (2 * k) + 1 <= n) {
    flip += (2 * k) + 1;
    cout << flip << " ";
  }
  cout << "\n";
}