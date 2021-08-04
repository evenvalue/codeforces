#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve(const vector<int> &primes) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  map<int, int> colour;
  int free = 1;
  for (const int x : a) {
    for (const int p : primes) {
      if (x % p) continue;
      if (colour[p]) break;
      colour[p] = free++;
      break;
    }
  }
  cout << free - 1 << '\n';
  for (const int x : a) {
    for (const int p : primes) {
      if (x % p) continue;
      cout << colour[p] << ' ';
      break;
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  int t = 1;
  cin >> t;
  while (t--) {
    solve(primes);
  }
}