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

vector<int> divisors(const int n) {
  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if (n % i) continue;
    div.push_back(i);
  }
  for (int i = (int)div.size() - 1; i >= 0; i--) {
    if (div[i] * div[i] == n) continue;
    div.push_back(n / div[i]);
  }
  reverse(div.begin(), div.end());
  return div;
}

int64 sum_till(const int x) {
  return (x * 1LL * (x + 1)) / 2;
}

void solve() {
  int n;
  cin >> n;
  const vector<int> div = divisors(n);
  for (const int k : div) {
    const int have_ball = n / k;
    cout << have_ball + k * sum_till(have_ball - 1) << ' ';
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