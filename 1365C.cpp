#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    diff[x - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    diff[x] += (i <= diff[x] ? -i : n - i);
  }
  sort(diff.begin(), diff.end());
  int ans = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    cnt = (diff[i] == diff[i - 1] ? cnt + 1 : 1);
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}