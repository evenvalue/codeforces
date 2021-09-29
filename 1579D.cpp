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

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  set<pair<int, int>> m(a.begin(), a.end());
  vector<pair<int, int>> ans;
  while (m.size() != 1) {
    if (m.begin()->first == 0) {
      m.erase(m.begin());
      continue;
    }
    auto f = *m.begin();
    auto s = *prev(m.end());
    m.erase(m.begin());
    m.erase(prev(m.end()));
    ans.emplace_back(f.second, s.second);
    f.first--, s.first--;
    m.insert(f), m.insert(s);
  }
  cout << ans.size() << '\n';
  for (const auto &[x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}