#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1] and i == s.length() - 1) {
      s[i] = (s[i] == 'a') ? 'b' : 'a';
    } else if (s[i] == s[i - 1]) {
      if (s[i] != 'a' and s[i + 1] != 'a') {
        s[i] = 'a';
      } else if (s[i] != 'b' and s[i + 1] != 'b') {
        s[i] = 'b';
      } else if (s[i] != 'c' and s[i + 1] != 'c') {
        s[i] = 'c';
      }
    }
  }
  cout << s << "\n";
}
