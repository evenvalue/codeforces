#include <array>
#include <iostream>
#include <vector>
using namespace std;

class dsu {
  vector<int> e;

public:
  explicit dsu(const int n) : e(n, -1) {}

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
    return true;
  }

  int operator[](const int x) {
    return e[x];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  array<vector<int>, 26> same;
  for (int x = 0; x < n; x++) {
    string s;
    cin >> s;
    for (const char c : s) {
      same[c - 'a'].push_back(x);
    }
  }
  dsu comp(n);
  for (int alpha = 0; alpha < 26; alpha++) {
    for (const int x : same[alpha]) {
      comp.unite(same[alpha][0], x);
    }
  }
  int ans = 0;
  for (int x = 0; x < n; x++) {
    ans += (comp[x] < 0);
  }
  cout << ans << '\n';
}