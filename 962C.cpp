#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
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

void solve(const int TestCase) {
  int n;
  cin >> n;
  string num = to_string(n);
  const int d = num.size();
  int ans = kInf;
  for (int i = 1; i * i <= n; i++) {
    string s = to_string(i * i);
    int s_idx = 0;
    for (int n_idx = 0; n_idx < d and s_idx < s.size(); n_idx++) {
      s_idx += (s[s_idx] == num[n_idx]);
    }
    if (s_idx == s.size()) ans = min(ans, d - s_idx);
  }
  cout << (ans == kInf ? -1 : ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto start = chrono::steady_clock::now();

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = chrono::steady_clock::now();
  double diff = chrono::duration_cast<chrono::seconds>(end - start).count();
  cerr << diff << '\n';
}