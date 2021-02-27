#include <iostream>
#include <set>
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
  multiset<int> s = {a[0]};
  int ans = 0;
  for (int i = 0, j = 1; i < n; i++) {
    while (*s.rbegin() - *s.begin() <= 1 and j < n) {
      s.insert(a[j]);
      j++;
    }
    if (*s.rbegin() - *s.begin() > 1) {
      s.erase(s.find(a[i]));
    }
    ans = max(ans, (int)s.size());
  }
  cout << ans << "\n";
}