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

vector<int> convert(const string &s) {
  vector<int> ans;
  ans.reserve(s.size());
  for (const char c : s) {
    if (c == '?') {
      ans.push_back(2);
    } else {
      ans.push_back(c == 'R' ? 0 : 1);
    }
  }
  return ans;
}

void output(const vector<int> &ans) {
  for (const int x : ans) {
    cout << (x == 0 ? 'R' : 'B');
  }
  cout << '\n';
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a = convert(s);
  for (int i = 1; i < n; i++) {
    if (a[i] != 2 or a[i - 1] == 2) continue;
    a[i] = 1 - a[i - 1];
  }
  if (a[n - 1] == 2) a[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] != 2) continue;
    a[i] = 1 - a[i + 1];
  }
  output(a);
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