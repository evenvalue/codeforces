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

vector<int> ask(const int n, const int x) {
  cout << "? " << x + 1 << endl;
  vector<int> d(n);
  for (int &node : d) {
    cin >> node;
  }
  return d;
}

void say(const vector<pair<int, int>> &edges) {
  cout << '!' << '\n';
  for (const auto [x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
  cout << flush;
}

void solve() {
  int n;
  cin >> n;
  vector<int> d = ask(n, 0);
  vector<int> red, blue;
  vector<pair<int, int>> edges;
  edges.reserve(n - 1);
  for (int x = 0; x < n; x++) {
    if (d[x] & 1) red.push_back(x);
    else blue.push_back(x);
    if (d[x] == 1) {
      edges.emplace_back(0, x);
    }
  }
  if (red.size() < blue.size() - 1) swap(red, blue);
  for (const int x : blue) {
    if (x == 0) continue;
    d = ask(n, x);
    for (int y = 1; y < n; y++) {
      if (d[y] != 1) continue;
      edges.emplace_back(x, y);
    }
  }
  say(edges);
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