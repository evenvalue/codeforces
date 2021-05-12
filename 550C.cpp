#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void yes(const vector<int> ans) {
  cout << "YES\n";
  for (const int x : ans) {
    cout << x;
  }
  cout << "\n";
  exit(0);
}

int integer(const char c) {
  return c - '0';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  const int n = s.size();
  for (int i = 0; i < n; i++) {
    const int x = integer(s[i]);
    if (x % 8 == 0) {
      yes({x});
    }
    for (int j = i + 1; j < n; j++) {
      const int y = integer(s[j]);
      if (((10 * x) + y) % 8 == 0) {
        yes({x, y});
      }
      for (int k = j + 1; k < n; k++) {
        const int z = integer(s[k]);
        if (((100 * x) + (10 * y) + z) % 8 == 0) {
          yes({x, y, z});
        }
      }
    }
  }
  cout << "NO\n";
}