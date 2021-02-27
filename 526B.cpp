#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  const int N = 1 << (n + 1);
  vector<int> a(N, 0);
  for (int i = 2; i < N; i++) {
    cin >> a[i];
  }
  int ans = 0;
  vector<int> dist(N, 0);
  for (int x = (N / 2) - 1; x > 0; x--) {
    const int left = dist[2 * x] + a[2 * x];
    const int right = dist[2 * x + 1] + a[2 * x + 1];
    ans += (left < right ? right - left : left - right);
    dist[x] = max(left, right);
  }
  cout << ans << "\n";
}