#include <iostream>
#include <vector>
using namespace std;

int bit_count(int x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 2;
  }
  return cnt;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) continue;
    ans = max(ans, bit_count(a[i] - a[i - 1]));
    a[i] = a[i - 1];
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}