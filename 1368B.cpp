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
  int64 k;
  cin >> k;
  string codeforces = "codeforces";
  vector<int> cnt(10, 1);
  int64 seq = 1;
  while (seq < k) {
    for (int i = 0; i < 10 and seq < k; i++) {
      seq /= cnt[i]++;
      seq *= cnt[i];
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << codeforces[i];
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}