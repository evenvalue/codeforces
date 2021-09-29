#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
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

struct point {
  int x{}, y{};

  explicit point() = default;
  explicit point(const int x, const int y) : x(x), y(y) {}

  point up() const {
    return *this + point(0, 1);
  }

  point down() const {
    return *this + point(0, -1);
  }

  point left() const {
    return *this + point(-1, 0);
  }

  point right() const {
    return *this + point(1, 0);
  }

  point clockwise90() const {
    return point(y, -x);
  }

  point anticlockwise90() const {
    return point(-y, x);
  }

  point operator+(const point &other) const {
    return point(x + other.x, y + other.y);
  }

  point& operator+=(const point &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  point operator-(const point &other) const {
    return point(x - other.x, y - other.y);
  }

  point& operator-=(const point &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  point& operator=(point other) {
    swap(x, other.x);
    swap(y, other.y);
    return *this;
  }

  bool operator<(const point &other) const {
    return (x != other.x ? x < other.x : y < other.y);
  }

  bool operator==(const point &other) const {
    return (x == other.x and y == other.y);
  }

  bool operator!=(const point &other) const {
    return not (*this == other);
  }

  friend ostream& operator<<(ostream &out, const point &p);
};

ostream& operator<<(ostream &out, const point &p) {
  return out << p.x << ' ' << p.y;
}

void solve(const int TestCase) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> coloured(n + 2, vector<bool>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      coloured[i][j] = (c == '*');
    }
  }
  vector<vector<int>> dcnt(n + 2, vector<int>(m + 2, -1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (not coloured[i][j]) continue;
      if (i == 1 and j == 3) {

      }
      point p1(j, i), p2(j, i);
      while (coloured[p1.y][p1.x] and coloured[p2.y][p2.x]) {
        p1 = p1.down().left();
        p2 = p2.down().right();
        dcnt[i][j]++;
      }
    }
  }
  bool yes = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (not coloured[i][j]) continue;
      bool b = false;
      int d = 0;
      point cur(j, i);
      while (coloured[cur.y][cur.x]) {
        if (dcnt[cur.y][cur.x] >= k) {
          b |= dcnt[cur.y][cur.x] >= d;
        }
        d++;
        cur = cur.up().left();
      }
      d = 0;
      cur = point(j, i);
      while (coloured[cur.y][cur.x]) {
        if (dcnt[cur.y][cur.x] >= k) {
          b |= dcnt[cur.y][cur.x] >= d;
        }
        d++;
        cur = cur.up().right();
      }
      yes &= b;
    }
  }
  cout << (yes ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}
