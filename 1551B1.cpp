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
  string s;
  cin >> s;
  const int n = s.size();
  vector<int> cnt(26);
  for (const char c : s) {
    cnt[c - 'a']++;
  }
  int mx = 0, mn = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 1) {
      mx++, mn++;
    } else {
      (mn < mx ? mn : mx) += cnt[i];
    }
  }
  cout << mn << '\n';
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