#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_map>
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
  vector<int> a(n);
  for (int &x : a) cin >> x;
  unordered_map<int, int> gcds;
  for (const int x : a) {
    int num = x;
    for (int i = 2; i * i <= x; i++) {
      if (num % i) continue;
      gcds[i]++;
      while (num % i == 0) {
        num /= i;
      }
    }
    if (num > 1) gcds[num]++;
  }
  int ans = 1;
  for (const auto [g, cnt] : gcds) {
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
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