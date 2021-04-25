#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<int> left(n);
  vector<int> right(n);
  left[0] = 1;
  right[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    left[i] = (a[i - 1] < a[i] ? left[i - 1] : 0) + 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    right[i] = (a[i] < a[i + 1] ? right[i + 1] : 0) + 1;
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = (i > 0 ? max(ans, left[i - 1] + 1) : ans);
    ans = (i < n - 1 ? max(ans, 1 + right[i + 1]) : ans);
    if (i > 0 and i < n - 1 and a[i - 1] + 1 < a[i + 1]) {
      ans = max(ans, left[i - 1] + 1 + right[i + 1]);
    }
  }
  cout << ans << "\n";
}