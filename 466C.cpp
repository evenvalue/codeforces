#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define int64 int64_t

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
  const int64 kSum = accumulate(a.begin(), a.end(), 0LL);
  if (abs(kSum) % 3) {
    cout << 0 << '\n';
    return 0;
  }
  const int64 grp = kSum / 3;
  int64 cnt = 0, sum = 0;
  int64 ans = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += a[i];
    ans += (sum == 2 * grp ? cnt : 0);
    cnt += (sum == grp);
  }
  cout << ans << '\n';
}