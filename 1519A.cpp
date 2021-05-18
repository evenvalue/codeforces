#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64 r, b, d;
    cin >> r >> b >> d;
    if (r < b) swap(r, b);
    cout << (r - b <= (b * d) ? "YES" : "NO") << "\n";
  }
}