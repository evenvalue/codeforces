#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<bool>> grid(n + 2, vector<bool>(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      grid[i][j] = (c == 'o');
    }
  }
  bool ans = false;
  vector<pair<int, int>> diff = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      for (auto [x, y] : diff) {
        cnt += grid[i + x][j + y];
      }
      ans |= (cnt & 1);
    }
  }
  cout << (ans ? "NO" : "YES") << '\n';
}