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

struct cave {
  int start = 0, end = 0;

  bool operator<(const cave &other) const {
    return start < other.start;
  }
};

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<cave> caves(n);
  for (cave &c : caves) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      if (const int level = c.start + i; level <= x) {
        c.start += x + 1 - level;
      }
    }
    c.end = c.start + k;
  }
  sort(caves.begin(), caves.end());
  int start = 0, level = 0;
  for (const cave &c : caves) {
    if (c.start <= level) {
      level += c.end - c.start;
    } else {
      start += c.start - level;
      level = c.end;
    }
  }
  cout << start << '\n';
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