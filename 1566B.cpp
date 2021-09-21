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

void solve(const int TestCase) {
  string s;
  cin >> s;
  const int n = s.size();
  if (s == string(n, '1')) {
    cout << 0 << '\n';
    return;
  }
  int front = 0, back = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      front++;
    } else {
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      back++;
    } else {
      break;
    }
  }
  if (n - front - back == count(s.begin() + front, s.begin() + (n - back), '0')) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}