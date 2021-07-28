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

string solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (string &s : v) {
    cin >> s;
  }

  auto check = [&](const string &str) -> bool {
    bool ret = true;
    for (const string &s : v) {
      int diff = 0;
      for (int i = 0; i < m; i++) {
        diff += (s[i] != str[i]);
      }
      ret &= (diff <= 1);
    }
    return ret;
  };

  string ans;
  for (int pos = 0; pos < m; pos++) {
    ans = v[0];
    for (char c = 'a'; c <= 'z'; c++) {
      ans[pos] = c;
      if (check(ans)) {
        return ans;
      }
    }
  }
  return "-1";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
}