#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  if (n == 1) return a[0];
  vector<int> m(n);
  vector<int> f(n);
  f[0] = a[0], f[1] = a[0] + a[1];
  m[0] = kInf, m[1] = f[0];
  for (int i = 2; i < n; i++) {
    m[i] = min(f[i - 1], f[i - 2]);
    f[i] = a[i] + min(m[i - 1], a[i - 1] + m[i - 2]);
  }
  return min(f[n - 1], m[n - 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
}