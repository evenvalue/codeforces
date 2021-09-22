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
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int step = 0;
  while (not is_sorted(a.begin(), a.end())) {
    for (int i = step & 1; i + 1 < n; i += 2) {
      if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    step++;
  }
  cout << step << '\n';
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