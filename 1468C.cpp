#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
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
  int q;
  cin >> q;
  int customer = 0;
  set<pair<int, int>> mono, poly;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int m;
      cin >> m;
      m = kInf - m;
      customer++;
      mono.insert({customer, m});
      poly.insert({m, customer});
    } else if (type == 2) {
      const pair<int, int> p = *mono.begin();
      cout << p.first << ' ';
      mono.erase(mono.begin());
      poly.erase(poly.find({p.second, p.first}));
    } else {
      const pair<int, int> p = *poly.begin();
      cout << p.second << ' ';
      poly.erase(poly.begin());
      mono.erase(mono.find({p.second, p.first}));
    }
  }
  cout << '\n';
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