#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<string> colours = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
  string dome = "blue";
  bool locked = false;
  while (n--) {
    string s;
    cin >> s;
    if (s == "lock" or s == "unlock") {
      locked = (s == "lock");
    } else if (not locked and (find(colours.begin(), colours.end(), s) != colours.end())) {
      dome = s;
    }
  }
  cout << dome;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}