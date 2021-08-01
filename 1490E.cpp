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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int64 sum = a[0].first;
  int disqualify = 0;
  for (int i = 1; i < n; i++) {
    disqualify = (a[i].first <= sum ? disqualify : i);
    sum += a[i].first;
  }
  vector<int> ans(n - disqualify);
  for (int i = disqualify; i < n; i++) {
    ans[i - disqualify] = a[i].second + 1;
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (const int x : ans) {
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