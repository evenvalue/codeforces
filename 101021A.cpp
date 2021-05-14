#include <iostream>
#include <vector>
using namespace std;

bool query(const int x) {
  cout << x << endl;
  string s;
  cin >> s;
  return (s == "<");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int l = 0, r = 1e6;
  while (l < r) {
    const int mid = (l + r + 1) / 2;
    if (query(mid)) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  cout << "! " << l << endl;
}