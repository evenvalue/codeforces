#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    const int n = s.length();
    vector<bool> change(n, false);
    for (int i = 2; i < n - 2; i++) {
      string cur = {s[i - 2], s[i - 1], s[i], s[i + 1], s[i + 2]};
      if (cur == "twone") change[i] = true;
    }
    for (int i = 0; i < n - 2; i++) {
      string cur = {s[i], s[i + 1], s[i + 2]};
      if (cur == "one" and not change[i]) change[i + 1] = true;
    }
    for (int i = 2; i < n; i++) {
      string cur = {s[i - 2], s[i - 1], s[i]};
      if (cur == "two" and not change[i]) change[i - 1] = true;
    }
    cout << count(change.begin(), change.end(), true) << "\n";
    for (int i = 0; i < n; i++) {
      if (change[i]) cout << i + 1 << " ";
    }
    cout << "\n";
  }
}