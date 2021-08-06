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
  int64 n, m, q;
  cin >> n >> m >> q;
  const int64 g = gcd(m, n);
  const int64 m_segment = m / g;
  const int64 n_segment = n / g;
  while (q--) {
    int64 t1, x, t2, y;
    cin >> t1 >> x >> t2 >> y;
    x--, y--;
    x /= (t1 == 1 ? n_segment : m_segment);
    y /= (t2 == 1 ? n_segment : m_segment);
    cout << (x == y ? "YES" : "NO") << '\n';
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