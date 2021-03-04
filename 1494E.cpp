#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  set<pair<int, int>> edges;
  set<pair<pair<int, int>, char>> edgec;
  int cycle = 0, uni_cycle = 0;
  auto add = [&](const pair<int, int> &edge, const char c) {
    edges.insert(edge);
    edgec.insert({edge, c});
    const pair<int, int> anti = {edge.second, edge.first};
    cycle += (edges.find(anti) != edges.end());
    uni_cycle += (edgec.find({anti, c}) != edgec.end());
  };

  auto remove = [&](const pair<int, int> &edge) {
    const pair<int, int> anti = {edge.second, edge.first};
    edges.erase(edge);
    if ((edges.find(anti) != edges.end())) {
      cycle--;
    }
    const char c = edgec.lower_bound({edge, 'a'})->second;
    edgec.erase({edge, c});
    if (edgec.find({anti, c}) != edgec.end()) {
      uni_cycle--;
    }
  };

  while (m--) {
    char type;
    cin >> type;
    if (type == '+') {
      int x, y;
      char c;
      cin >> x >> y >> c;
      add({x, y}, c);
    } else if (type == '-') {
      int x, y;
      cin >> x >> y;
      remove({x, y});
    } else {
      int k;
      cin >> k;
      cout << (uni_cycle or (k % 2 == 1 and cycle) ? "YES" : "NO") << "\n";
    }
  }
}