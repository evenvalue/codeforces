#include <iostream>
#include <vector>
#include <set>
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
  int n;
  cin >> n;
  dsu city(n);
  vector<pair<int, int>> unused;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    if (not city.unite(x - 1, y - 1)) {
      unused.emplace_back(x, y);
    }
  }
  vector<int> country;
  {
    set<int> comp;
    for (int i = 0; i < n; i++) {
      if(comp.insert(city.find(i)).second) {
        country.push_back(i + 1);
      }
    }
  }
  const int sz = country.size();
  cout << sz - 1 << "\n";
  for (int i = 0; i + 1 < sz; i++) {
    cout << unused[i].first << " " << unused[i].second << " ";
    cout << country[i] << " " << country[i + 1] << "\n";
  }
}