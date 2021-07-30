#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

pair<int, int> add(const pair<int, int> &x, const pair<int, int> &y) {
  return make_pair(x.first + y.first, x.second + y.second);
}

bool solve(map<char, pair<int, int>> &dir) {
  string s;
  cin >> s;
  const int n = s.size();
  vector<pair<int, int>> path = {{0, 0}};
  path.reserve(n + 1);
  for (int i = 0; i < n; i++) {
    path.push_back(add(path.back(), dir[s[i]]));
  }
  if (path.size() <= path.back().first + path.back().second) return false;
  sort(path.begin(), path.end());
  path.erase(unique(path.begin(), path.end()), path.end());
  return (path.size() == (n + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<char, pair<int, int>> dir;
  dir['L'] = {0, -1};
  dir['R'] = {0, 1};
  dir['U'] = {-1, 0};
  dir['D'] = {1, 0};

  int t = 1;
  //cin >> t;
  while (t--) {
    cout << (solve(dir) ? "OK" : "BUG") << '\n';
  }
}