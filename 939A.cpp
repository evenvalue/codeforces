#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

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
  for (int x = 0; x < n; x++) {
    if (x != p[p[p[x]]]) continue;
    cout << "YES";
    return;
  }
  cout << "NO";
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