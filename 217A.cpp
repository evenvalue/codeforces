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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> drift(n);
  for (auto &d : drift) {
    cin >> d.first >> d.second;
  }
  dsu drifts(n);
  int comp = n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((drift[i].first == drift[j].first) or (drift[i].second == drift[j].second)) {
        comp -= drifts.unite(i, j);
      }
    }
  }
  cout << comp - 1 << '\n';
}