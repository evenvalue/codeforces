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

int ask(const int i, const int j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  int sum;
  cin >> sum;
  return sum;
}

void say(const vector<int> &a) {
  cout << "! ";
  for (const int x : a) {
    cout << x << ' ';
  }
  cout << endl;
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  const int s1 = ask(0, 1);
  const int s2 = ask(1, 2);
  const int s3 = ask(0, 2);
  vector<int> a(n);
  a[0] = (s1 + s2 + s3) / 2 - s2;
  a[1] = s1 - a[0];
  a[2] = s2 - a[1];
  for (int i = 3; i < n; i++) {
    const int s = ask(0, i);
    a[i] = s - a[0];
  }
  say(a);
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