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

int assign(int prv, int nxt) {
  if (prv != 1 and nxt != 1) return 1;
  if (prv != 2 and nxt != 2) return 2;
  return 3;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  const vector<int> b = a;
  a.erase(unique(a.begin(), a.end()), a.end());
  if (a[0] == a.back()) a.pop_back();
  const int n2 = a.size();
  if ((n2 & 1) and (n2 == n)) {
    cout << 3 << '\n' << 3 << ' ';
    for (int i = 1; i < n; i++) {
      cout << (i & 1) + 1 << ' ';
    }
  } else if (a.empty()) {
    cout << 1 << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 << ' ';
    }
  } else if (n & 1) {
    cout << 2 << '\n' << 1 << ' ';
    bool same_taken = false;
    for (int i = 1; i < n; i++) {
      if (not same_taken and b[i] == b[i - 1]) same_taken = true;
      if (same_taken) {
        cout << 2 - (i & 1);
      } else {
        cout << (i & 1) + 1;
      }
      cout << ' ';
    }
  } else {
    cout << 2 << '\n';
    for (int i = 0; i < n; i++) {
      cout << (i & 1) + 1 << ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}