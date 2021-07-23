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

void solve() {
  string s, t;
  cin >> s >> t;
  while (not s.empty() and not t.empty()) {
    if (s.back() == t.back()) {
      s.pop_back(), t.pop_back();
    } else if (s.size() == 1) {
      break;
    } else {
      s.pop_back(), s.pop_back();
    }
  }
  cout << (t.empty() ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}