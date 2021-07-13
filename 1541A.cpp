#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n';

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << 3 << ' ' << 1 << ' ' << 2 << ' ';
    for (int i = 4; i <= n; i += 2) {
      cout << i + 1 << ' ' << i << ' ';
    }
    cout << '\n';
  } else {
    for (int i = 1; i <= n; i += 2) {
      cout << i + 1 << ' ' << i << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}