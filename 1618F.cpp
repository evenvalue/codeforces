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

string to_binary(int64 x) {
  string binary;
  while (x) {
    if (x & 1) {
      binary += '1';
    } else {
      binary += '0';
    }
    x >>= 1;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}

void yes() {
  cout << "YES\n";
  exit(0);
}

void no() {
  cout << "NO\n";
  exit(0);
}

string op1(string b) {
  while (b.back() == '0') {
    b.pop_back();
  }
  reverse(b.begin(), b.end());
  return b;
}

string op2(string b) {
  b.push_back('1');
  reverse(b.begin(), b.end());
  return b;
}

int ones_in(const string &s) {
  return (int) count(s.begin(), s.end(), '1');
}

void solution() {
  const int64 a = readInt64(), b = readInt64();
  string bin_a = to_binary(a), bin_b = to_binary(b);

  if (bin_a == bin_b) yes();

  auto can_go = [&](const string &bin) {
    if (bin_b.find(bin) == string::npos) return false;
    const int ones = ones_in(bin_b) - ones_in(bin);
    return ((int) (bin_b.size() - bin.size()) == ones);
  };

  string s = op1(bin_a);
  if (can_go(s)) yes();
  if (can_go(op1(s))) yes();

  s = op2(bin_a);
  if (can_go(s)) yes();
  if (can_go(op1(s))) yes();

  no();
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