#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

class dsu {
  vector<int> e;

public:
  int comp;

  explicit dsu(const int n) : e(n, -1), comp(n) {}

  int find(const int x) {
    return e[x] < 0 ? x : (e[x] = find(e[x]));
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    comp--;
    return true;
  }

  int size(const int x) {
    return -e[find(x)];
  }

  int operator[](const int x) {
    return e[x];
  }
};

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> puzzle;
  vector<pair<int, int>> pos(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x - 1].first = i;
  }
  dsu d(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x - 1].second = i;
  }
  for (int i = 0; i < n; i++) {
    d.unite(pos[i].first, pos[i].second);
  }
  int ans = 1;
  for (int i = 1; i <= d.comp; i++) {
    ans += ans;
    ans -= (ans > kMod ? kMod : 0);
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}