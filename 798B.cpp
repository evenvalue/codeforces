#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int steps(string s1, int move, string s2) {
  rotate(s1.begin(), s1.begin() + move, s1.end());
  for (int i = 0; i < s1.length(); i++) {
    if (s2 == s1) return i;
    rotate(s2.begin(), s2.begin() + 1, s2.end());
  }
  cout << -1 << "\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  for (string &str : s) {
    cin >> str;
  }
  const int m = s[0].length();
  vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ans[i] += steps(s[0], i, s[j]);
    }
  }
  cout << *min_element(ans.begin(), ans.end()) << "\n";
}