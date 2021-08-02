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
  int n, m;
  cin >> n >> m;
  int survive = n;
  auto check = [](int &x, int &y) {
    x--, y--;
    if (x > y) swap(x, y);
  };
  vector<int> in_deg(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    check(x, y);
    survive -= (in_deg[x] == 0);
    in_deg[x]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      check(x, y);
      survive -= (in_deg[x] == 0);
      in_deg[x]++;
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      check(x, y);
      in_deg[x]--;
      survive += (in_deg[x] == 0);
    } else {
      cout << survive << '\n';
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