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
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> a(n), b(m);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  vector<int> ans;
  ans.reserve(n + m);
  for (int i = 0, j = 0; i < n or j < m;) {
    if (i != n and a[i] <= k) {
      ans.push_back(a[i]);
      k += (a[i] == 0);
      i++;
    } else if (j != m and b[j] <= k) {
      ans.push_back(b[j]);
      k += (b[j] == 0);
      j++;
    } else {
      ans.clear();
      ans.push_back(-1);
      break;
    }
  }
  for (int &x : ans) {
    cout << x << ' ';
  }
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