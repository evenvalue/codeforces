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
  vector<bool> princess(n, false);
  vector<bool> prince(n, false);
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    for (int j = 0; j < sz; j++) {
      int x;
      cin >> x;
      x--;
      if (princess[i] or prince[x]) continue;
      princess[i] = prince[x] = true;
    }
  }
  const int i = distance(princess.begin(), find(princess.begin(), princess.end(), false));
  const int j = distance(prince.begin(), find(prince.begin(), prince.end(), false));
  if (i == n) {
    cout << "OPTIMAL";
  } else {
    cout << "IMPROVE\n";
    cout << i + 1 << ' ' << j + 1;
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