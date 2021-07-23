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

int check(const string &s) {
  int team1 = 0, team2 = 0;
  for (int i = 0; i < 10; i++) {
    team1 += ((i & 1) == 0 ? s[i] - '0' : 0);
    team2 += ((i & 1) ? s[i] - '0' : 0);
    const int remain = 10 - i - 1;
    if (remain / 2 + team1 < team2) return i + 1;
    if ((remain + 1) / 2 + team2 < team1) return i + 1;
  }
  return 10;
}

void solve() {
  string s;
  cin >> s;
  auto p1 = s;
  for (int i = 0; i < 10; i++) {
    if (p1[i] != '?') continue;
    if (i & 1) {
      p1[i] = '0';
    } else {
      p1[i] = '1';
    }
  }
  auto p2 = s;
  for (int i = 0; i < 10; i++) {
    if (p2[i] != '?') continue;
    if (i & 1) {
      p2[i] = '1';
    } else {
      p2[i] = '0';
    }
  }
  cout << min(check(p1), check(p2)) << '\n';
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