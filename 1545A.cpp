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
  vector<int> a((n + 1) / 2), b(n / 2);
  for (int i = 0; i < n; i++) {
    cin >> (i & 1 ? b : a)[i / 2];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = (i & 1 ? b : a)[i / 2];
  }
  cout << (is_sorted(ans.begin(), ans.end()) ? "YES" : "NO");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}