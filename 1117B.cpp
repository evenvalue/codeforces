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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  if (n == 1) {
    cout << k * a[0] << '\n';
    return;
  }
  sort(a.rbegin(), a.rend());
  const int second = m / (k + 1);
  const int first = m - second;
  cout << (int64) first * a[0] + (int64) second * a[1] << '\n';
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