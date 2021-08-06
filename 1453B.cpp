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
  int n;
  cin >> n;
  vector<int64> a(n);
  for (int64 &x : a) cin >> x;
  int64 operations = 0;
  for (int i = n - 1; i > 0; i--) {
    operations += abs(a[i] - a[i - 1]);
  }
  int64 reduction = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
  for (int i = 1; i < n - 1; i++) {
    const int64 before = abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]);
    const int64 after = abs(a[i + 1] - a[i - 1]);
    reduction = max(reduction, before - after);
  }
  cout << operations - reduction << '\n';
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