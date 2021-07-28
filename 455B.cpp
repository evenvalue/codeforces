#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

namespace evenvalue {
class trie {
  vector<vector<int>> t;
  vector<bool> terminal;
  int free;

public:
  explicit trie() {
    t.emplace_back(26, -1);
    terminal.push_back(false);
    free = 1;
  }

  // Adds string s to the trie.
  // Time Complexity: O(s.length()).
  void add(const string &s) {
    int x = 0;
    for (const char c : s) {
      if (t[x][c - 'a'] == -1) {
        t.emplace_back(26, -1);
        terminal.push_back(false);
        t[x][c - 'a'] = free++;
      }
      x = t[x][c - 'a'];
    }
    terminal[x] = true;
  }

  //Returns the number of nodes in the trie.
  //Time Complexity: O(1).
  [[nodiscard]] int nodes() const {
    return free;
  }

  //Returns the node index of x.secondTh child of x.first, if any, else returns -1.
  //Time Complexity: O(1).
  int operator[](const pair<int, int> &x) const {
    assert(0 <= x.first and x.first < free);
    assert(0 <= x.second and x.second <= t[x.first].size());
    return t[x.first][x.second];
  }

  //Returns whether node x is a terminal node or not.
  //Time Complexity: O(1).
  bool operator[](const int x) const {
    assert(0 <= x and x < free);
    return terminal[x];
  }
};
}// namespace evenvalue

bool solve() {
  evenvalue::trie t;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    t.add(s);
  }
  vector<bool> win(t.nodes(), false);
  vector<bool> lose(t.nodes(), false);
  function<void(int)> dfs = [&](const int x) {
    bool leaf = true;
    for (int c = 0; c < 26; c++) {
      if (const int y = t[{x, c}]; y != -1) {
        dfs(y);
        win[x] = win[x] or not win[y];
        lose[x] = lose[x] or not lose[y];
        leaf = false;
      }
    }
    if (leaf) lose[x] = true;
  };
  dfs(0);
  if (not win[0]) {
    return false;
  } else if (lose[0]) {
    return true;
  } else {
    return (k & 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    cout << (solve() ? "First" : "Second") << '\n';
  }
}