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

void reject() {
  cout << "No\n";
  exit(0);
}

void accept() {
  cout << "Yes\n";
  exit(0);
}

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  string s2 = s;
  s2.erase(unique(s2.begin(), s2.end()), s2.end());
  const int n = s.size(), m = s2.size();
  if (n < 4 or m > 4 or m == 1) reject();
  if (m >= 3) accept();
  if (s[0] != s[1] or s[n - 1] != s[n - 2]) reject();
  accept();
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