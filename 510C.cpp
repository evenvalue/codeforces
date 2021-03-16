#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (string &x : a) {
    cin >> x;
  }
  vector<vector<int>> g(26);

  auto add_edge = [&](const string &sa, const string &sb) -> bool {
    for (int i = 0; i < min(sa.length(), sb.length()); i++) {
      if (sa[i] != sb[i]) {
        g[sa[i] - 'a'].push_back(sb[i] - 'a');
        return true;
      }
    }
    return (sa.length() < sb.length());
  };
  auto reject = []() {
    cout << "Impossible\n";
    exit(0);
  };
  for (int i = 0; i < n - 1; i++) {
    bool res = add_edge(a[i], a[i + 1]);
    if (not res) reject();
  }
  vector<bool> visited(26, false);
  vector<bool> entered(26, false);
  vector<int> topsort;
  function<void(int)> dfs_cycle = [&](int x) {
    visited[x] = entered[x] = true;
    for (int y : g[x]) {
      if (entered[y]) reject();
      if (visited[y]) continue;
      dfs_cycle(y);
    }
    entered[x] = false;
    topsort.push_back(x);
  };
  for (int i = 0; i < 26; i++) {
    if (not visited[i]) dfs_cycle(i);
  }
  reverse(topsort.begin(), topsort.end());
  for (int i = 0; i < 26; i++) {
    cout << (char) ('a' + topsort[i]);
  }
  cout << "\n";
}