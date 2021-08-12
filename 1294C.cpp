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
  int a = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i) continue;
    a = i;
    break;
  }
  n /= a;
  int b = n;
  for (int i = 2; i * i <= n; i++) {
    if (i == a or n % i) continue;
    b = i;
    break;
  }
  int c = n / b;
  if (a > 1 and b > 1 and c > 1 and c != a and c != b) {
    cout << "YES" << '\n' << a << ' ' << b << ' ' << c;
  } else {
    cout << "NO";
  }
  cout << '\n';
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