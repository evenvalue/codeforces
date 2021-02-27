#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> path;
  for (int city = 0; city < n; city++) {
    int b;
    cin >> b;
    path[b - city] += b;
  }
  int ans = 0;
  for (const auto &journey : path) {
    ans = max(ans, journey.second);
  }
  cout << ans << "\n";
}