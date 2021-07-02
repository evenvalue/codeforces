#include <algorithm>
#include <array>
#include <iostream>
#include <map>
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
  string s;
  cin >> n >> s;
  map<pair<int, int>, int> freq;
  int d = 0, k = 0;
  for (const char c : s) {
    d += (c == 'D');
    k += (c == 'K');
    const int g = gcd(d, k);
    cout << ++freq[{d / g, k / g}] << ' ';
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