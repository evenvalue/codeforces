#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
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

const double pi = acos(-1);

double degree_to_radians(const double degree) {
  return degree * (pi / 180);
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  n *= 2;
  const double theta = ((double) 180 * (n - 2)) / (2 * n);
  cout << setprecision(10) << tan(degree_to_radians(theta)) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto start = chrono::steady_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = chrono::steady_clock::now();
  double diff = chrono::duration_cast<chrono::seconds>(end - start).count();
  cerr << diff << '\n';
}