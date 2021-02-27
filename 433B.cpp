#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &s : v) {
    cin >> s;
  }
  vector<int> t1(n + 1, 0);
  t1[1] = v[0];
  for (int i = 2; i <= n; i++) {
    t1[i] = t1[i - 1] + v[i - 1];
  }
  sort(v.begin(), v.end());
  vector<int> t2(n + 1, 0);
  t2[1] = v[0];
  for (int i = 2; i <= n; i++) {
    t2[i] = t2[i - 1] + v[i - 1];
  }
  int m;
  cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << t1[r] - t1[l - 1] << "\n";
    } else {
      cout << t2[r] - t2[l - 1] << "\n";
    }
  }
}