#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  double p;
  cin >> n >> p;
  double happy = 1;
  while (n > 0) {
    if (n & 1) {
      happy = happy * (1 - p) + (1 - happy) * p;
    }
    p = 2 * p * (1 - p);
    n /= 2;
  }
  cout << setprecision(15) << happy << "\n";
}