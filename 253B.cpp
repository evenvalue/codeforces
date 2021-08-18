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

void solve() {
  int n;
  fin >> n;
  vector<int> a(n);
  for (int &x : a) fin >> x;
  sort(a.begin(), a.end());
  int ans = n;
  for (int i = 0; i < n; i++) {
    ans = min(ans, i + (int) distance(upper_bound(a.begin(), a.end(), 2 * a[i]), a.end()));
  }
  fout << ans << '\n';
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