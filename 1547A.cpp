#include <algorithm>
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
  pair<int, int> a, b, f;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  cin >> f.first >> f.second;
  int ans = abs(a.first - b.first) + abs(a.second - b.second);
  if (a.first == b.first and a.first == f.first) {
    ans += (min(a.second, b.second) < f.second and f.second < (max(a.second, b.second)) ? 2 : 0);
  } else if (a.second == b.second and a.second == f.second) {
    ans += (min(a.first, b.first) < f.first and f.first < (max(a.first, b.first)) ? 2 : 0);
  }
  cout << ans;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}