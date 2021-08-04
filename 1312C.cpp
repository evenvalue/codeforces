#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int64> a(n);
  for (int64 &x : a) cin >> x;
  const int64 mx = *max_element(a.begin(), a.end());
  int64 powk = 1;
  while (powk <= mx) {
    powk *= k;
  }
  multiset<int64> num(a.begin(), a.end());
  while (powk) {
    if (const auto it = prev(num.end()); powk <= *it) {
      const int64 x = *it - powk;
      num.erase(it);
      num.insert(x);
    }
    powk /= k;
  }
  cout << (num.upper_bound(0) == num.end() ? "YES" : "NO") << '\n';
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