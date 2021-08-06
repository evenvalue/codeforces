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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<int> w1;
  vector<int> w2;
  for (int &x : a) {
    if (x > 0) {
      w1.push_back(x);
    } else {
      w2.push_back(-x);
    }
  }
  const int64 s1 = accumulate(w1.begin(), w1.end(), 0LL);
  const int64 s2 = accumulate(w2.begin(), w2.end(), 0LL);
  if (s1 == s2) {
    auto check = [&]() {
      if (w1 == w2) return "-";
      for (int i = 0, j = 0; i < w1.size() and j < w2.size(); i++, j++) {
        if (w1[i] == w2[j]) continue;
        return (w1[i] > w2[j] ? "first" : "second");
      }
      return (w1.size() > w2.size() ? "first" : "second");
    };
    if (const string s = check(); s != "-") {
      cout << s << '\n';
    } else {
      cout << (a[n - 1] > 0 ? "first" : "second") << '\n';
    }
  } else {
    cout << (s1 > s2 ? "first" : "second") << '\n';
  }
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