#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

vector<int> ask(const int n, const int x) {
  cout << "? " << x + 1 << endl;
  vector<int> d(n);
  for (int &node : d) {
    cin >> node;
  }
  return d;
}

void say(const vector<vector<int>> &g) {
  const int n = g.size();
  cout << '!' << endl;
  for (int x = 0; x < n; x++) {
    for (int y = x + 1; y < n; y++) {
      if (!g[x][y]) continue;
      cout << x + 1 << ' ' << y + 1 << endl;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> d = ask(n, 0);
  vector<int> red, blue;
  vector<vector<int>> g(n, vector<int>(n));
  for (int x = 0; x < n; x++) {
    if (d[x] & 1) red.push_back(x);
    else blue.push_back(x);
    if (d[x] == 1) {
      g[0][x] = g[x][0] = 1;
    }
  }
  if (red.size() < blue.size() - 1) swap(red, blue);
  for (const int x : blue) {
    if (x == 0) continue;
    d = ask(n, x);
    for (int y = 0; y < n; y++) {
      if (d[y] != 1) continue;
      g[x][y] = g[y][x] = 1;
    }
  }
  say(g);
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