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
const int kInf = 2e9;
const int kMod = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> temp(n, kInf);
  {
    vector<int> a(k);
    for (int &x : a) cin >> x;
    for (int i = 0; i < k; i++) {
      int t;
      cin >> t;
      temp[a[i] - 1] = t;
    }
  }
  for (int i = 1; i < n; i++) {
    temp[i] = min(temp[i], temp[i - 1] + 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    temp[i] = min(temp[i], temp[i + 1] + 1);
  }
  for (const int room : temp) {
    cout << room << ' ';
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