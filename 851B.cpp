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
using ld = long double;

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

ld dist(const point &p1, const point &p2) {
  const int run = p2.x - p1.x;
  const int rise = p2.y - p1.y;
  return sqrt((run * 1LL * run) + (rise * 1LL * rise));
}

void solve(const int TestCase) {
  point a, b, c;
  cin >> a >> b >> c;
  const ld ab = dist(a, b), bc = dist(b, c), ac = dist(a, c);
  cout << (ab + bc != ac and ab == bc ? "Yes" : "No") << '\n';
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