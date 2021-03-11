#include <algorithm>
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

struct edge {
  int x;
  int y;
  int w;

  bool operator<(const edge &other) const {
    return w < other.w;
  }
};

int increase(dsu &kruskal, vector<edge> &edges) {
  int res = 0;
  for (edge &e : edges) {
    if (not kruskal.unite(e.x, e.y)) {
      res++;
    }
  }
  edges.clear();
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<edge> edges(m);
  for (edge &e : edges) {
    cin >> e.x >> e.y >> e.w;
    e.x--;
    e.y--;
  }
  sort(edges.begin(), edges.end());
  int cost = 0;
  dsu kruskal(n);
  vector<edge> same;
  int ans = 0;
  for (const edge &e : edges) {
    if (e.w == cost) {
      if (kruskal.find(e.x) != kruskal.find(e.y)) {
        same.push_back(e);
      }
    } else {
      ans += increase(kruskal, same);
      cost = e.w;
      if (kruskal.find(e.x) != kruskal.find(e.y)) {
        same.push_back(e);
      }
    }
  }
  cout << ans + increase(kruskal, same) << "\n";
}