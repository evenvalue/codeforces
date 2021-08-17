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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int found_at = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1 and a[i - 1] == 0) {
      found_at = i - 1;
      break;
    }
  }
  if (a[n] == 0) found_at = n;
  if (found_at == -1) {
    cout << -1  << '\n';
    return;
  }
  vector<int> path;
  path.reserve(n + 2);
  for (int x = 0; x <= n; x++) {
    path.push_back(x);
    if (x == found_at) {
      path.push_back(n + 1);
    }
  }
  for (int i = 1; i < path.size(); i++) {
    cout << path[i] << ' ';
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