#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> small;
  vector<int> large;
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    vector<int> a(len);
    for (int &x : a) {
      cin >> x;
    }
    if (is_sorted(a.crbegin(), a.crend())) {
      small.push_back(a[len - 1]);
      large.push_back(a[0]);
    }
  }
  sort(small.begin(), small.end());
  sort(large.begin(), large.end());
  const int sz = small.size();
  long long ans = n * 1LL * n;
  for (int i = 0, j = 0; i < sz and j < sz;) {
    if (small[i] >= large[j]) {
      ans -= sz - i;
      j++;
    } else {
      i++;
    }
  }
  cout << ans << "\n";
}