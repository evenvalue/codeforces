#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  vector<int> penalty(n);
  for (int i = 0; i < m; i++) {
    penalty[i] = a[i];
  }
  for (int i = m; i < n; i++) {
    penalty[i] = penalty[i - m] + a[i];
  }
  vector<int> ans(n, a[0]);
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1] + penalty[i];
  }
  for (const int x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}