#include <algorithm>
#include <iostream>

using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int p, a, b, c;
    cin >> p >> a >> b >> c;
    a = ((p + a - 1) / a) * a;
    b = ((p + b - 1) / b) * b;
    c = ((p + c - 1) / c) * c;
    cout << min({a, b, c}) - p << "\n";
  }
}