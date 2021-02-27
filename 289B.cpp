#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  const int sz = n * m;
  vector<int> a(sz);
  cin >> a[0];
  const int mod = a[0] % d;
  for (int i = 1; i < sz; i++) {
    cin >> a[i];
    if (a[i] % d != mod) {
      cout << -1 << "\n";
      return 0;
    }
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int x : a) {
    ans += (x - a[0]) / d;
  }
  for (int hub = a[0] + d; hub <= a[sz - 1]; hub += d) {
    int loss = distance(a.begin(), lower_bound(a.begin(), a.end(), hub));
    if (ans <= ans + loss - sz + loss) {
      cout << ans << "\n";
      return 0;
    }
    ans = ans + loss - sz + loss;
  }
  cout << ans << "\n";
}