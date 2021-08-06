#include <algorithm>
#include <array>
#include <cassert>
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
  int n, k;
  string s;
  cin >> n >> k >> s;
  int last = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '*') {
      last = i;
      break;
    }
  }
  int pos = distance(s.begin(), find(s.begin(), s.end(), '*'));
  s[pos] = 'x';
  while (pos < last) {
    for (int j = pos + k; j > pos; j--) {
      if (s[j] == '*') {
        pos = j;
        s[pos] = 'x';
        break;
      }
    }
  }
  s[last] = 'x';
  cout << count(s.begin(), s.end(), 'x') << '\n';
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