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

void solve() {
  int n, capacity;
  fin >> n >> capacity;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    fin >> c[i];
    c[i] *= (n - i);
  }
  vector<vector<int>> best(n, vector<int>(capacity + 1));
  for (int food = c[0]; food <= capacity; food++) {
    best[0][food] = 1;
  }
  for (int i = 1; i < n; i++) {
    best[i] = best[i - 1];
    for (int food = c[i]; food <= capacity; food++) {
      best[i][food] = max(best[i][food], best[i - 1][food - c[i]] + 1);
    }
  }
  fout << best[n - 1][capacity] << '\n';
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