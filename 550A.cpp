#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  const int n = s.length();
  bool found = false;
  for (int i = 1; i < n; i++) {
    if (not found and s[i] == 'B' and s[i - 1] == 'A') {
      found = true;
      i++;
    } else if (found and s[i] == 'A' and s[i - 1] == 'B') {
      cout << "YES\n";
      return 0;
    }
  }
  found = false;
  for (int i = 1; i < n; i++) {
    if (not found and s[i] == 'A' and s[i - 1] == 'B') {
      found = true;
      i++;
    } else if (found and s[i] == 'B' and s[i - 1] == 'A') {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}