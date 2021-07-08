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

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (j - i <= n / 2) {
          cout << 1 << ' ';
        } else {
          cout << -1 << ' ';
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (j - i < n / 2) {
          cout << 1 << ' ';
        } else if (j - i == n / 2) {
          cout << 0 << ' ';
        } else {
          cout << -1 << ' ';
        }
      }
    }
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
    cout << '\n';
  }
}