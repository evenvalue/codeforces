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

  point &operator+=(const point &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  point operator-(const point &other) const {
    return point(x - other.x, y - other.y);
  }

  point &operator-=(const point &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  point &operator=(point other) {
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
    return not(*this == other);
  }

  friend ostream &operator<<(ostream &out, const point &p);

  friend istream &operator>>(istream &in, point &p);
};

ostream &operator<<(ostream &out, const point &p) {
  return out << p.x << ' ' << p.y;
}

istream &operator>>(istream &in, point &p) {
  return in >> p.x >> p.y;
}

long double dist(const point &p1, const point &p2) {
  const int run = p2.x - p1.x;
  const int rise = p2.y - p1.y;
  return sqrt((run * 1LL * run) + (rise * 1LL * rise));
}

char dir(const point &p1, const point &p2) {
  const point diff = p2 - p1;
  if (diff.y > 0) {
    return 'U';
  } else if (diff.y < 0) {
    return 'D';
  } else if (diff.x > 0) {
    return 'R';
  } else {
    return 'L';
  }
}

bool check(const char c1, const char c2) {
  if (c1 == 'R' and c2 == 'U') return true;
  if (c1 == 'D' and c2 == 'R') return true;
  if (c1 == 'L' and c2 == 'D') return true;
  if (c1 == 'U' and c2 == 'L') return true;
  return false;
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  string s;
  point prev;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    point cur;
    cin >> cur;
    s += dir(prev, cur);
    prev = cur;
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += check(s[i], s[i + 1]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}