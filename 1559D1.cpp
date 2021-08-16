#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
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

class dsu {
  const int n;
  vector<int> e;
  int comp = 0;

public:
  explicit dsu(const int n) : n(n), e(n, -1), comp(n) {}

  int find(const int x) {
    assert(0 <= x and x < n);
    return e[x] < 0 ? x : (e[x] = find(e[x]));
  }

  bool unite(int x, int y) {
    assert(0 <= x and x < n);
    assert(0 <= y and y < n);
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    comp--;
    return true;
  }

  bool same(int x, int y) {
    assert(0 <= x and x < n);
    assert(0 <= y and y < n);
    return (find(x) == find(y));
  }

  int size(const int x) {
    assert(0 <= x and x < n);
    return -e[find(x)];
  }

  int operator[](const int x) {
    assert(0 <= x and x < n);
    return e[x];
  }
};

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu mocha(n), diana(n);
  for (int i = 0; i < m1; i++) {
    int x, y;
    cin >> x >> y;
    mocha.unite(x - 1, y - 1);
  }
  for (int i = 0; i < m2; i++) {
    int x, y;
    cin >> x >> y;
    diana.unite(x - 1, y - 1);
  }
  vector<pair<int, int>> edges;
  for (int x = 0; x < n; x++) {
    for (int y = x + 1; y < n; y++) {
      if (not mocha.same(x, y) and not diana.same(x, y)) {
        mocha.unite(x, y), diana.unite(x, y);
        edges.emplace_back(x, y);
      }
    }
  }
  cout << edges.size() << '\n';
  for (const auto &[x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
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