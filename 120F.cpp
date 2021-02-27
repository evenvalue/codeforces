#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int diameter(const vector<vector<int>> &g) {
  auto bfs = [&](int start) -> pair<int, int> {
    const int n = g.size();
    vector<int> d(n, 0);
    vector<bool> visit(n, false);
    queue<int> q;
    q.push(start);
    while (not q.empty()) {
      int x = q.front();
      q.pop();
      visit[x] = true;
      for (int nbr : g[x]) {
        if (visit[nbr]) continue;
        q.push(nbr);
        d[nbr] = d[x] + 1;
      }
    }
    int far = distance(d.begin(), max_element(d.begin(), d.end()));
    return {d[far], far};
  };
  int x = bfs(0).second;
  return bfs(x).first;
}

int main() {
  ifstream fin("input.txt");
  int s;
  fin >> s;
  int ans = 0;
  while (s--) {
    int n;
    fin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      fin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ans += diameter(g);
  }
  ofstream fout("output.txt");
  fout << ans << "\n";
}