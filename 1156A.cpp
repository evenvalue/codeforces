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

int more(int x, int y) {
  if (x > y) swap(x, y);
  if (x == 1 and y == 2) {
    return 3;
  } else if (x == 1 and y == 3) {
    return 4;
  } else {
    return 500;
  }
}

bool check(const int x, const int y, const int z) {
  return (x == 3 and y == 1 and z == 2);
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += more(a[i], a[i + 1]);
  }
  for (int i = 0; i < n - 2; i++) {
    ans -= check(a[i], a[i + 1], a[i + 2]);
  }
  if (ans >= 500) {
    cout << "Infinite\n";
  } else {
    cout << "Finite\n";
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}