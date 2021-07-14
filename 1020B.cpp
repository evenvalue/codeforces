#include <algorithm>
#include <array>
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
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &x : p) {
    cin >> x;
    x--;
  }
  vector<bool> visit(n, false);
  function<int(int)> dfs = [&](const int x) {
    visit[x] = true;
    if (visit[p[x]]) return p[x];
    return dfs(p[x]);
  };
  for (int x = 0; x < n; x++) {
    visit.assign(n, false);
    visit[x] = true;
    cout << dfs(x) + 1 << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}