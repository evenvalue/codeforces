#include <iostream>
#include <string>
using namespace std;

string solve(const int n, int k) {
  pair<int, int> b;
  for (int i = n - 2; i >= 0; i--) {
    int decrease = n - 1 - i;
    if (k <= decrease) {
      b.first = i;
      break;
    } else {
      k -= decrease;
    }
  }
  b.second = n - k;
  string ans;
  ans.reserve(n);
  for (int i = 0; i < n; i++) {
    if (i == b.first or i == b.second) {
      ans.push_back('b');
    } else {
      ans.push_back('a');
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
  }
}