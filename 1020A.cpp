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
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 != x2) {
      int go;
      if (y1 > b) go = b;
      else if (y1 < a)
        go = a;
      else
        go = y1;
      cout << abs(x1 - x2) + abs(y1 - go) + abs(y2 - go) << '\n';
    } else {
      cout << abs(y1 - y2) << '\n';
    }
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