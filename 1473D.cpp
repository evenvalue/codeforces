#include <algorithm>
#include <array>
#include <cassert>
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

struct range {
  int at = 0;
  int lo = 0, hi = 0;

  range operator+(const range &other) const {
    range ret;
    ret.at = at + other.at;
    ret.lo = min(lo, at + other.lo);
    ret.hi = max(hi, at + other.hi);
    return ret;
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<range> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i].at = pref[i - 1].at + (s[i - 1] == '+' ? 1 : -1);
    pref[i].lo = min(pref[i - 1].lo, pref[i].at);
    pref[i].hi = max(pref[i - 1].hi, pref[i].at);
  }
  vector<range> suff(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    const int add = (s[i] == '+' ? 1 : -1);
    suff[i].at = suff[i + 1].at + add;
    suff[i].lo = min(0, add + suff[i + 1].lo);
    suff[i].hi = max(0, add + suff[i + 1].hi);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    const range ans = pref[l - 1] + suff[r];
    cout << ans.hi - ans.lo + 1 << '\n';
  }
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