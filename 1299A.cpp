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

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<int> pref(n, INT_MAX), suff(n, INT_MAX);
  for (int i = 1, j = n - 2; i < n and j >= 0; i++, j--) {
    pref[i] = pref[i - 1] & (~a[i - 1]);
    suff[j] = suff[j + 1] & (~a[j + 1]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (const int x = pref[i] & a[i] & suff[i]; x > ans) {
      swap(a[i], a[0]);
      ans = x;
    }
  }
  for (const int x : a) cout << x << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);  
  }
}