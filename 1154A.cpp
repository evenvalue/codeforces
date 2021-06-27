#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  array<int, 4> a{};
  for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0; i < 3; i++) {
    cout << a[3] - a[i] << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}