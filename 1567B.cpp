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

void solve(const int TestCase, const vector<int> &xor_till) {
  int a, b;
  cin >> a >> b;
  const int x = xor_till[a - 1];
  cout << (x == b ? a : a + 1 + ((b ^ x) == a)) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kMaxA = 3e5 + 10;
  vector<int> xor_till(kMaxA);
  for (int i = 1; i < kMaxA; i++) {
    xor_till[i] = xor_till[i - 1] ^ i;
  }

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc, xor_till);
  }
}