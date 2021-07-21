#include <algorithm>
#include <array>
#include <cmath>
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

bool solve() {
  string s;
  cin >> s;
  int cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    cnt = (s[i] == s[i - 1] ? cnt + 1 : 1);
    if (cnt == 7) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}