#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> diff(n);
  for (int &x : diff) {
    cin >> x;
  }
  for (int &x : diff) {
    int y;
    cin >> y;
    x -= y;
  }
  sort(diff.begin(), diff.end());
  int64 ans = -(int) count_if(diff.begin(), diff.end(), [](const int x) {
    return x > 0;
  });
  for (const int x : diff) {
    const int take = n - (int) distance(diff.begin(), upper_bound(diff.begin(), diff.end(), 0 - x));
    ans += take;
  }
  cout << ans / 2 << '\n';
}