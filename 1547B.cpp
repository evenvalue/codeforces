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
  string s;
  cin >> s;
  const int n = s.size();
  const int pos = distance(s.begin(), find(s.begin(), s.end(), 'a'));
  if (pos == n) {
    cout << "NO";
    return;
  }
  int lo = pos - 1, hi = pos + 1;
  for (int i = 1; i < n; i++) {
    if (lo != -1 and s[lo] == 'a' + i) {
      lo--;
    } else if (hi != n and s[hi] == 'a' + i) {
      hi++;
    } else {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
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