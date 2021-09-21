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

struct foo {
  int sight;
  int index;

  bool operator<(const foo &other) const {
    return (sight != other.sight ? sight < other.sight : index > other.index);
  }
};

void solve(const int TestCase) {
  int m, n;
  cin >> m >> n;
  assert(m == 1);
  vector<foo> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].sight;
    a[i].index = i;
  }
  const vector<foo> d = a;
  sort(a.begin(), a.end());
  vector<bool> taken(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    const int pos = distance(a.begin(), lower_bound(a.begin(), a.end(), d[i]));
    ans += count(taken.begin(), taken.begin() + pos + 1, true);
    taken[pos] = true;
  }
  cout << ans << '\n';
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