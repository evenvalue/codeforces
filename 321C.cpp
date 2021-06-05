#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class CentroidDecomp {
  const vector<vector<int>> t;
  vector<int> P;
  vector<int> sz;

public:
  explicit CentroidDecomp(const int n, const vector<vector<int>> &g) : t(g), P(n, -2), sz(n) {
    build(0, -1);
  }

  void build(const int x, const int p) {
    const int ct = find_centroid(find_size(x, -1), x, -1);
    P[ct] = p;
    for (const int y : t[ct]) {
      if (P[y] != -2) continue;
      build(y, ct);
    }
  }

  int find_size(const int x, const int p) {
    sz[x] = 1;
    for (const int y : t[x]) {
      if (P[y] != -2 or y == p) continue;
      sz[x] += find_size(y, x);
    }
    return sz[x];
  }

  int find_centroid(const int size, const int x, const int p) {
    for (const int y : t[x]) {
      if (P[y] != -2 or y == p) continue;
      if (sz[y] * 2 > size) return find_centroid(size, y, x);
    }
    return x;
  }

  int operator[](const int x) {
    return P[x];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    t[x].push_back(y);
    t[y].push_back(x);
  }
  CentroidDecomp CeDe(n, t);
  vector<vector<int>> cd(n);
  int root;
  for (int x = 0; x < n; x++) {
    if (CeDe[x] == -1) {
      root = x;
    } else {
      cd[CeDe[x]].push_back(x);
    }
  }
  vector<int> depth(n);
  function<void(int, int)> dfs = [&](const int x, const int level) {
    depth[x] = level;
    for (const int y : cd[x]) {
      dfs(y, level + 1);
    }
  };
  dfs(root, 0);
  if (*max_element(depth.begin(), depth.end()) > 25) {
    cout << "Impossible!\n";
  } else {
    for (int x = 0; x < n; x++) {
      cout << (char)('A' + depth[x]) << ' ';
    }
    cout << '\n';
  }
}