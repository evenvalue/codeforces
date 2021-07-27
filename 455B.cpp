#include <algorithm>
#include <array>
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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> trie(1, vector<int>(26, -1));
  int free = 1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x = 0;
    for (const char c : s) {
      if (trie[x][c - 'a'] == -1) {
        trie[x][c - 'a'] = free++;
        trie.emplace_back(26, -1);
      }
      x = trie[x][c - 'a'];
    }
  }
  vector<bool> win(free, false);
  vector<bool> lose(free, false);
  function<void(int)> dfs = [&](const int x) {
    bool leaf = true;
    for (int c = 0; c < 26; c++) {
      if (const int y = trie[x][c]; y != -1) {
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
    cout << "Second";
  } else if (win[0] and lose[0]) {
    cout << "First";
  } else {
    cout << (k & 1 ? "First" : "Second");
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}