#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int64 kInf = 1e15 + 10;

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<vector<int64>> best(n, vector<int64>(n + 1, -kInf));
  for (int i = 0; i < n; i++) {
    best[i][0] = 0;
  }
  best[0][1] = (a[0] >= 0 ? a[0] : -kInf);
  for (int i = 1; i < n; i++) {
    for (int drink = 1; drink <= n; drink++) {
      best[i][drink] = max(best[i - 1][drink], (best[i - 1][drink - 1] + a[i] < 0 ? -kInf : best[i - 1][drink - 1] + a[i]));
    }
  }
  for (int drink = n; drink >= 0; drink--) {
    if (best[n - 1][drink] < 0) continue;
    cout << drink << '\n';
    return 0;
  }
}