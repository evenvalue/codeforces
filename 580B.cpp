#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <fstream>
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

ifstream fin("input.txt");
ofstream fout("output.txt");

struct fri {
  int money;
  int happy;

  bool operator<(const fri &other) const {
    return money < other.money;
  }
};

void solve() {
  int n, d;
  cin >> n >> d;
  vector<fri> friends(n);
  for (fri &f : friends) cin >> f.money >> f.happy;
  sort(friends.begin(), friends.end());
  int64 ans = 0, sum = 0;
  for (int l = 0, r = 0; l < n; l++) {
    r = max(l + 1, r);
    sum = max(sum, (int64)friends[l].happy);
    while (r < n) {
      if (friends[r].money >= friends[l].money + d) break;
      sum += friends[r].happy;
      r++;
    }
    ans = max(ans, sum);
    sum -= friends[l].happy;
  }
  cout << ans << '\n';
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