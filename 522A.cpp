#include <iostream>
#include <map>
#include <string>
using namespace std;

void lower(char &c) {
  if ('A' <= c and c <= 'Z') {
    c -= 'A';
    c += 'a';
  }
}

int main() {
  map<string, int> spread;
  spread["polycarp"] = 1;
  int n;
  cin >> n;
  while (n--) {
    string s1, reposted, s2;
    cin >> s1 >> reposted >> s2;
    for (char &c : s1) {
      lower(c);
    }
    for (char &c : s2) {
      lower(c);
    }
    spread[s1] = spread[s2] + 1;
  }
  int ans = 0;
  for (pair<string, int> chain : spread) {
    ans = max(ans, chain.second);
  }
  cout << ans << "\n";
}