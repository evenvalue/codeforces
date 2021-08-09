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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  a.push_back(kInf);
  vector<int> b = a;
  sort(b.begin(), b.end());
  int subarrays = (a[n - 1] == b[n - 1]);
  for (int i = 0; i < n; i++) {
    const auto it = upper_bound(b.begin(), b.end(), a[i]);
    subarrays += (a[i + 1] != *it);
  }
  cout << (subarrays <= k ? "YES" : "NO") << '\n';
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