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
  vector<pair<int, int>> v(n);
  for (auto &[a, _] : v) cin >> a;
  for (auto &[_, b] : v) cin >> b;
  vector<int> inc, dec;
  for (int i = 0; i < n; i++) {
    auto [a, b] = v[i];
    if (a < b) {
      while (a < b) {
        inc.push_back(i);
        a++;
      }
    } else {
      while (b < a) {
        dec.push_back(i);
        b++;
      }
    }
  }
  if (inc.size() != dec.size()) {
    cout << -1 << '\n';
    return;
  }
  cout << inc.size() << '\n';
  for (int i = 0; i < inc.size(); i++) {
    cout << dec[i] + 1 << ' ' << inc[i] + 1 << '\n';
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