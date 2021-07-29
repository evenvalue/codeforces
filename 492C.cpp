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
  int n, r, avg;
  cin >> n >> r >> avg;
  int64 req = (int64)avg * n;
  vector<pair<int, int>> exams(n);
  int64 sum = 0;
  for (pair<int, int> &exam : exams) {
    cin >> exam.second >> exam.first;
    sum += exam.second;
  }
  sort(exams.begin(), exams.end());
  int64 write = 0;
  for (auto [b, a] : exams) {
    if (sum >= req) break;
    write += min((int64)r - a, req - sum) * b;
    sum += min((int64)r - a, req - sum);
  }
  cout << write << '\n';
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