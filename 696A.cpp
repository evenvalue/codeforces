#include <iostream>
#include <map>
using namespace std;

#define int int64_t

int lca(int x, int y) {
  while (x != y) {
    if (x > y) {
      x /= 2;
    } else {
      y /= 2;
    }
  }
  return x;
}

int32_t main() {
  int q;
  cin >> q;
  map<int, int> weight;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    const int anc = lca(x, y);
    if (type == 1) {
      int w;
      cin >> w;
      while (x != anc) {
        weight[x] += w;
        x /= 2;
      }
      while (y != anc) {
        weight[y] += w;
        y /= 2;
      }
    } else {
      int ans = 0;
      while (x != anc) {
        ans += weight[x];
        x /= 2;
      }
      while (y != anc) {
        ans += weight[y];
        y /= 2;
      }
      cout << ans << "\n";
    }
  }
}