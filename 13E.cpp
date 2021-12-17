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

namespace cp {
class sqrt_decomp {
  struct hole {
    int next;
    int jump;
  };

  const int kBlockSize = 500;

  const int n;
  vector<int> a;
  vector<hole> b;

  [[nodiscard]] int block_of(const int i) const {
    return i / kBlockSize;
  }

public:
  explicit sqrt_decomp(const vector<int> &a) : n(a.size()), a(a), b(n) {
    update(n - 1, a[0]);
    for (int i = block_of(n - 1) * kBlockSize - 1; i >= 0; i -= kBlockSize) {
      update(i, a[i]);
    }
  }

  void update(const int pos, const int pow) {
    a[pos] = pow;
    for (int i = pos; i >= block_of(pos) * kBlockSize; i--) {
      const int j = i + a[i];
      if (j >= n) {
        b[i].next = i;
        b[i].jump = 0;
      } else if (block_of(i) != block_of(j)) {
        b[i].next = j;
        b[i].jump = 1;
      } else {
        b[i].next = b[j].next;
        b[i].jump = b[j].jump + 1;
      }
    }
  }

  [[nodiscard]] pair<int, int> query(int i) const {
    int jumps = 1;
    while (b[i].next != i) {
      jumps += b[i].jump;
      i = b[i].next;
    }
    return make_pair(i, jumps);
  }
};
}

void solution() {
  const int n = readInt(), q = readInt();
  const vector<int> &a = readVec<int>(n);
  cp::sqrt_decomp s(a);
  for (int i = 0; i < q; i++) {
    const int type = readInt();
    if (type == 0) {
      const int pos = readInt() - 1, pow = readInt();
      s.update(pos, pow);
    } else {
      const auto &[last, jumps] = s.query(readInt() - 1);
      cout << last + 1 << ' ' << jumps << '\n';
    }
  }
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