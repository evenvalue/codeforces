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
  int n;
  cin >> n;
  vector<vector<int>> u(n);
  {
    vector<int> uni(n);
    for (int &x : uni) cin >> x;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      u[uni[i] - 1].push_back(s);
    }
    for (vector<int> &university : u) {
      sort(university.rbegin(), university.rend());
    }
  }
  vector<vector<int64>> pref(n);
  for (int i = 0; i < n; i++) {
    int64 prev = 0;
    pref[i].reserve(u[i].size());
    for (int j = 0; j < u[i].size(); j++) {
      pref[i].push_back(prev + u[i][j]);
      prev = pref[i].back();
    }
  }
  vector<int64> ans(n);
  for (int i = 0; i < n; i++) {
    const int sz = u[i].size();
    for (int k = 1; k <= sz; k++) {
      ans[k - 1] += pref[i][sz - (sz % k) - 1];
    }
  }
  for (int64 &x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}