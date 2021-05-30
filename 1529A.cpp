#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    const int mn = *min_element(a.begin(), a.end());
    const int ans = n - (int)count(a.begin(), a.end(), mn);
    cout << ans << '\n';
  }
}