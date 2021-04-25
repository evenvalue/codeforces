#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int &x : a) {
    cin >> x;
  }
  for (int &x : b) {
    cin >> x;
  }
  for (int ans = 0; ans < (1 << 9); ans++) {
    bool correct = true;
    for (int i = 0; i < n; i++) {
      bool ok = false;
      for (int j = 0; j < m; j++) {
        ok |= (((a[i] & b[j]) | ans) == ans);
      }
      correct &= ok;
    }
    if (not correct) continue;
    cout << ans << "\n";
    return 0;
  }
}