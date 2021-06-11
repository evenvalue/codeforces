#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  const int mx = distance(a.begin(), max_element(a.begin(), a.end()));
  const int mn = distance(a.begin(), min_element(a.begin(), a.end()));
  const int front = max(mx, mn) + 1;
  const int back = n - min(mx, mn);
  const int mid = min(mx, mn) + 1 + n - max(mx, mn);
  cout << min({front, back, mid}) << '\n';
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