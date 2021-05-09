#include <iostream>
using namespace std;

#define int int64_t

void solve() {
  int a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << "NO";
  } else {
    cout << "YES\n";
    cout << a << " ";
    cout << a * ((2 * b) - 1) << " ";
    cout << 2 * a * b << " ";
  }
  cout << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}