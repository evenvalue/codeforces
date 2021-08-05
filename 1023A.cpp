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
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  if (n < m and count(s.begin(), s.end(), '*') == 0) t.clear();
  while (not s.empty() and not t.empty()) {
    if (s.back() == '*') {
      while (s.back() == '*') {
        s.pop_back();
      }
      while (not t.empty() and s != t) {
        t.pop_back();
      }
    } else {
      if (s.back() != t.back()) break;
      while (not s.empty() and not t.empty() and s.back() == t.back()) {
        s.pop_back(), t.pop_back();
      }
    }
  }
  while (not s.empty() and s.back() == '*') {
    s.pop_back();
  }
  cout << (s.empty() ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}