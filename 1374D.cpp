#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
      x = (k - (x % k)) % k;
    }
    sort(a.rbegin(), a.rend());
    int64 num = a[0], occ = 1, cur_occ = 1;
    for (int i = 1; i < n and a[i] != 0; i++) {
      cur_occ = (a[i] == a[i - 1] ? cur_occ + 1 : 1);
      num = (cur_occ > occ ? a[i] : num);
      occ = max(occ, cur_occ);
    }
    const int64 x = (k * (occ - 1)) + num;
    cout << (x == 0 ? 0 : x + 1) << '\n';
  }
}