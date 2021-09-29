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

struct build {
  unsigned int n;
  vector<int> b;

  explicit build(const unsigned int n) : n(n), b(n) {}

  int &at(const int x) {
    assert(0 <= x and x < n);
    return b[x];
  }

  int operator[](const int x) const {
    return b[x];
  }

  [[nodiscard]] unsigned int size() const {
    return b.size();
  }

  bool operator<(const build &other) const {
    assert(other.size() == n);
    for (int i = 0; i < b.size(); i++) {
      if (b[i] != other[i]) return b[i] < other[i];
    }
    return false;
  }

  build &operator=(build other) {
    swap(n, other.n);
    swap(b, other.b);
    return *this;
  }
};

vector<build> next_builds(const build &b) {
  vector<build> ret;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == 0) continue;
    ret.push_back(b);
    ret.back().at(i)--;
  }
  return ret;
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (vector<int> &slot : a) {
    int c;
    cin >> c;
    slot.reserve(c);
    for (int i = 0; i < c; i++) {
      int x;
      cin >> x;
      slot.push_back(x);
    }
  }
  int m;
  cin >> m;
  set<build> banned;
  while (m--) {
    build b(n);
    for (int &x : b.b) {
      cin >> x;
      x--;
    }
    banned.insert(b);
  }
  build best(n);
  for (int i = 0; i < n; i++) best.at(i) = (int) a[i].size() - 1;
  if (banned.find(best) == banned.end()) {
    for (const int x : best.b) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
    return;
  }
  pair<int, build> ans = make_pair(0, build(n));
  for (const build &b : banned) {
    vector<build> next = next_builds(b);
    for (const build &nxt : next) {
      if (banned.find(nxt) != banned.end()) continue;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += a[i][nxt[i]];
      }
      ans = max(ans, make_pair(sum, nxt));
    }
  }
  for (const int x : ans.second.b) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
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