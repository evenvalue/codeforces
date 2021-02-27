#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  string s, m;
  cin >> n >> s >> m;
  sort(s.begin(), s.end());
  sort(m.begin(), m.end());
  int ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    int hit = (m[i] < s[j]);
    ans += hit;
    j += not hit;
  }
  cout << ans << "\n";
  ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    int hit_sherlock = (m[i] > s[j]);
    ans += hit_sherlock;
    j += hit_sherlock;
  }
  cout << ans << "\n";
}