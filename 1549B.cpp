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
  int n;
  string s, t;
  cin >> n >> s >> t;
  s = '0' + s + '0';
  t = '0' + t + '0';
  vector<bool> taken(n + 2, false);
  for (int i = 1; i <= n; i++) {
    if (t[i] == '0') continue;
    if (s[i] == '0') {
      taken[i] = true;
    } else if (s[i - 1] == '1' and not taken[i - 1]) {
      taken[i - 1] = true;
    } else if (s[i + 1] == '1' and not taken[i + 1]) {
      taken[i + 1] = true;
    }
  }
  cout << count(taken.begin(), taken.end(), true) << '\n';
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