#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

using int64 = int64_t;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

[[maybe_unused]] int readInt() {
  int x;
  cin >> x;
  return x;
}
[[maybe_unused]] int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
[[maybe_unused]] char readChar() {
  char c;
  cin >> c;
  return c;
}
[[maybe_unused]] string readString() {
  string s;
  cin >> s;
  return s;
}
[[maybe_unused]] double readDouble() {
  return stod(readString());
}
[[maybe_unused]] ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
[[maybe_unused]] pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
[[maybe_unused]] vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
[[maybe_unused]] vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

const int64 kInf64 = 2e18 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void compress(vector<int> &a) {
  map<int, int> m;
  for (const int x : a) {
    m[x] = 0;
  }
  for (int i = 0; auto &[x, v] : m) {
    v = i++;
  }
  for (int &x : a) {
    x = m[x];
  }
}

void solution() {
  const int n = readInt();
  vector<int> a = readVec<int>(n);

  compress(a);

  vector<int> freq(n);

  auto set_back_freq = [&](const int l, const int r) {
    for (int i = 0; i < l; i++) {
      freq[a[i]] = 0;
    }
    for (int i = r + 1; i < n; i++) {
      freq[a[i]] = 0;
    }
  };

  auto check = [&](const int l, const int r) {
    for (int i = 0; i < l; i++) {
      if (++freq[a[i]] > 1) {
        set_back_freq(l, r);
        return false;
      }
    }
    for (int i = r + 1; i < n; i++) {
      if (++freq[a[i]] > 1) {
        set_back_freq(l, r);
        return false;
      }
    }
    set_back_freq(l, r);
    return true;
  };

  auto bs = [&](const int l) {
    int lo = l, hi = n;
    while (lo < hi) {
      const int mid = (lo + hi) / 2;
      if (check(l, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  };

  if (check(n, n)) {
    cout << 0 << '\n';
    return;
  }

  int ans = n;
  for (int l = 0; l < n; l++) {
    const int r = bs(l);
    if (r == n) continue;
    ans = min(ans, r - l + 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solution();
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}