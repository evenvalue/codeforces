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
  int n;
  string s;
  cin >> n >> s;
  const int one = count(s.begin(), s.end(), 'n');
  const int zero = count(s.begin(), s.end(), 'z');
  for (int i = 0; i < one; i++) cout << 1 << ' ';
  for (int i = 0; i < zero; i++) cout << 0 << ' ';
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