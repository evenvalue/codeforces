#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <fstream>
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

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> ans;

void solve(const int a, const int b, const int a_serve, const int b_serve) {
  for (int a_break = max(0, a - a_serve); a_break <= min(a, b_serve); a_break++) {
    const int a_hold = a - a_break;
    const int b_break = a_serve - a_hold;
    if (b_break < 0 or b_break > b) continue;
    ans.push_back(a_break + b_break);
  }
  for (int b_break = max(0, b - b_serve); b_break <= min(b, a_serve); b_break++) {
    const int b_hold = b - b_break;
    const int a_break = b_serve - b_hold;
    if (a_break < 0 or a_break > a) continue;
    ans.push_back(a_break + b_break);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  const int first = (a + b + 1) / 2;
  const int second = (a + b) / 2;
  solve(a, b, first, second);
  solve(a, b, second, first);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << '\n';
  for (const int x : ans) cout << x << ' ';
  cout << '\n';
  ans.clear();
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