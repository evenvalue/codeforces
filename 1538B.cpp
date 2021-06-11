#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define int64 int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  const int64 sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum % n != 0) {
    cout << -1 << '\n';
    return;
  }
  const int64 avg = sum / n;
  const int ans = count_if(a.begin(), a.end(), [&avg](const int x) {
    return x > avg;
  });
  cout << ans << '\n';
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