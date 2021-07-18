#include <algorithm>
#include <array>
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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  sort(a.begin(), a.end()), sort(b.begin(), b.end());
  a.reserve(2 * n), b.reserve(2 * n);
  for (int i = 0; i < n; i++) {
    a.push_back(100), b.push_back(0);
  }
  auto check = [&](const int stages) -> bool {
    int score_a = 0, score_b = 0;
    int remove = stages / 4;
    for (int i = remove; i < stages; i++) {
      score_a += a[i];
    }
    int subtract = stages - n;
    for (int i = max(0, remove - subtract); i < stages - subtract; i++) {
      score_b += b[i];
    }
    return score_a >= score_b;
  };
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(n + mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}