#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
    x = (x > 0);
  }
  vector<int> pos(n), neg(n);
  pos[0] = a[0];
  neg[0] = 1 - a[0];
  for (int r = 1; r < n; r++) {
    if (a[r]) {
      pos[r] = pos[r - 1] + 1;
      neg[r] = neg[r - 1];
    } else {
      pos[r] = neg[r - 1];
      neg[r] = pos[r - 1] + 1;
    }
  }
  cout << accumulate(neg.begin(), neg.end(), 0LL) << " ";
  cout << accumulate(pos.begin(), pos.end(), 0LL) << "\n";
}