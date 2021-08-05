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

int ask(const int i, const int j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  int product;
  cin >> product;
  return product;
}

void say(const array<int, 6> &a) {
  cout << "! ";
  for (const int x : a) {
    cout << x << ' ';
  }
  cout << endl;
  exit(0);
}

void common(pair<int, int> &p1, pair<int, int> &p2) {
  if (p1.first == p2.first) {
    swap(p1.first, p1.second);
  } else if (p1.first == p2.second) {
    swap(p1.first, p1.second);
    swap(p2.first, p2.second);
  } else if (p1.second == p2.second) {
    swap(p2.first, p2.second);
  }
}

void solve() {
  const array<int, 6> num = {4, 8, 15, 16, 23, 42};
  map<int, pair<int, int>> m;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      m[num[i] * num[j]] = {num[i], num[j]};
    }
  }
  array<int, 6> a{};
  pair<int, int> p1 = m[ask(0, 1)];
  pair<int, int> p2 = m[ask(1, 2)];
  common(p1,p2);
  a[0] = p1.first, a[1] = p1.second, a[2] = p2.second;
  p1 = m[ask(3, 4)];
  p2 = m[ask(4, 5)];
  common(p1, p2);
  a[3] = p1.first, a[4] = p1.second, a[5] = p2.second;
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