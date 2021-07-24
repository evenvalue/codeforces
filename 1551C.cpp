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

struct cnt {
  array<int, 5> a;

  cnt operator+(const cnt &other) const {
    cnt res{};
    for (int i = 0; i < 5; i++) {
      res.a[i] = a[i] + other.a[i];
    }
    return res;
  }
};

bool comp(const cnt &x, const cnt &y, const int i) {
  const int contrib_x = 2 * x.a[i] - accumulate(x.a.begin(), x.a.end(), 0);
  const int contrib_y = 2 * y.a[i] - accumulate(y.a.begin(), y.a.end(), 0);
  return contrib_x > contrib_y;
}

bool check(const cnt &c, const int i) {
  const int sum = accumulate(c.a.begin(), c.a.end(), 0);
  return (sum - c.a[i] < c.a[i]);
}

void solve() {
  int n;
  cin >> n;
  vector<cnt> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (const char c : s) {
      v[i].a[c - 'a']++;
    }
  }
  function<int(int)> answer = [&](const int i) {
    sort(v.begin(), v.end(), [&](const cnt &x, const cnt &y) {
      return comp(x, y, i);
    });
    int ans = 0;
    cnt cur = {0, 0, 0, 0, 0};
    for (;ans < n; ans++) {
      cur = cur + v[ans];
      if (not check(cur, i)) break;
    }
    return ans;
  };
  int ans = 0;
  for (const int alpha : {0, 1, 2, 3, 4}) {
    ans = max(ans, answer(alpha));
  }
  cout << ans << '\n';
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