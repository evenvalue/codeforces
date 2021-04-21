#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    const int sum_of_coins = (1 << (x + 1)) - 2;
    const int pile_a = (1 << x) + (1 << (x / 2)) - 2;
    const int pile_b = sum_of_coins - pile_a;
    cout << pile_a - pile_b << "\n";
  }
}