#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto &row : a) {
    for (int &cell : row) {
      cin >> cell;
    }
  }
  vector<int> value(n);
  vector<int> par(n);
  int idx = n;
  function<int(const vector<int> &)> build = [&](const vector<int> &l) {
    if (l.size() == 1) {
      const int root = l[0];
      value[root] = a[root][root];
      return root;
    }
    const int root = idx;
    idx++;
    value.push_back(0);
    par.push_back(0);
    for (int node : l) {
      value[root] = max(value[root], a[l[0]][node]);
    }
    vector<vector<int>> groups;
    for (const int x : l) {
      bool in_group = false;
      for (auto &group : groups) {
        if (a[group[0]][x] != value[root]) {
          group.push_back(x);
          in_group = true;
          break;
        }
      }
      if (not in_group) {
        groups.push_back({x});
      }
    }
    for (const auto &group : groups) {
      par[build(group)] = root;
    }
    return root;
  };
  vector<int> leaf(n);
  iota(leaf.begin(), leaf.end(), 0);
  const int root = build(leaf);
  cout << value.size() << "\n";
  for (int x : value) {
    cout << x << " ";
  }
  cout << "\n" << root + 1 << "\n";
  for (int i = 0; i < par.size(); i++) {
    if (i == root) continue;
    cout << i + 1 << " " << par[i] + 1 << "\n";
  }
}