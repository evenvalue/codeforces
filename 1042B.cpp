#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const int inf = 1e9 + 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  map<string, int> drink;
  while (n--) {
    int cost;
    string s;
    cin >> cost >> s;
    sort(s.begin(), s.end());
    if (not drink[s] or cost < drink[s]) {
      drink[s] = cost;
    }
  }
  int ans = inf;
  if (drink["A"] and drink["B"] and drink["C"]) {
    ans = drink["A"] + drink["B"] + drink["C"];
  }
  if (drink["ABC"]) {
    ans = min(ans, drink["ABC"]);
  }
  auto buy = [&](const string s1, const string s2) -> int {
    if (not drink[s1] or not drink[s2]) {
      return inf;
    }
    return drink[s1] + drink[s2];
  };
  ans = min(ans, buy("AB", "C"));
  ans = min(ans, buy("A", "BC"));
  ans = min(ans, buy("AC", "B"));
  ans = min(ans, buy("AB", "BC"));
  ans = min(ans, buy("AC", "BC"));
  ans = min(ans, buy("AC", "AB"));
  cout << (ans == inf ? -1 : ans) << "\n";
}