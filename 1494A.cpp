#include <iostream>
#include <string>
using namespace std;

bool check(const string &s) {
  int cnt = 0;
  for (char c : s) {
    if (c == '(') {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt < 0) {
      return false;
    }
  }
  return (cnt == 0);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool possible = false;
    for (int mask = 0; mask < 8; mask++) {
      string brkt;
      for (char c : s) {
        if (mask & 1 << (c - 'A')) {
          brkt += '(';
        } else {
          brkt += ')';
        }
      }
      possible |= check(brkt);
    }
    cout << (possible ? "YES" : "NO") << "\n";
  }
}