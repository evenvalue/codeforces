#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
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

int mex(int c1, int c2) {
  const int mn = min(c1, c2);
  const int mx = max(c1, c2);
  if (mn == 0 and mx == 0) {
    return 1;
  } else if (mn == 0 and mx == 1) {
    return 2;
  } else {
    return 0;
  }
}

int mex(const int x1, const int x2, const int x3, const int x4) {
  const int mn = min({x1, x2, x3, x4});
  const int mx = max({x1, x2, x3, x4});
  if (mn == 0 and mx == 0) {
    return 1;
  } else if (mn == 0 and mx == 1) {
    return 2;
  } else {
    return 0;
  }
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (char &c : s1) c -= '0';
  for (char &c : s2) c -= '0';
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = mex(s1[i], s2[i]);
  }
  if (n == 1) {
    cout << v[0] << '\n';
    return;
  }
  vector<int> ans(n);
  ans[0] = v[0];
  ans[1] = max(v[0] + v[1], mex(s1[0], s2[0], s1[1], s2[1]));
  for (int i = 2; i < n; i++) {
    ans[i] = max(ans[i - 1] + v[i], ans[i - 2] + mex(s1[i], s2[i], s1[i - 1], s2[i - 1]));
  }
  cout << ans[n - 1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}