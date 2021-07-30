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
  auto print = [&](const int i) {
    for (int j = n - i - 1; j >= 0; j--) {
      cout << ' ' << ' ';
    }
    for (int j = 0; j < i; j++) {
      cout << j << ' ';
    }
    for (int j = i; j >= 0; j--) {
      cout << j;
      if (j) cout << ' ';
    }
    cout << '\n';
  };
  for (int i = 0; i <= n; i++) {
    print(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    print(i);
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
  }
}