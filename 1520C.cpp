#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << "\n";
    return;
  }
  const int mx = n * n;
  int cur_num = 1;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cur_num > mx) {
        cur_num = 2;
      }
      mat[i][j] = cur_num;
      cur_num += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}