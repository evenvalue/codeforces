#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0, streak = 0, prev = 1e9 + 5;
  while (n--) {
    int cur;
    cin >> cur;
    if (cur <= 2 * prev) {
      streak++;
    } else {
      streak = 1;
    }
    prev = cur;
    ans = max(ans, streak);
  }
  cout << ans << "\n";
}