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
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = a[i - 1] ^ pref[i - 1];
  }
  bool ans = (pref[n] == 0);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans |= (pref[i - 1] == (pref[j - 1] ^ pref[i - 1]) and pref[i - 1] == (pref[n] ^ pref[j - 1]));
    }
  }
  cout << (ans ? "YES" : "NO") << '\n';
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