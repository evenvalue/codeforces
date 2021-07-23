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

bool find_back(const string &s, const string &t, const int pos) {
  if (pos + 1 < t.size()) return false;
  for (int i = pos, j = 0; i >= 0, j < t.size(); i--, j++) {
    if (s[i] == t[j]) continue;
    return false;
  }
  return true;
}

bool solve() {
  string s, t;
  cin >> s >> t;
  vector<int> start;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[0]) start.push_back(i);
  }
  for (int right = 0; right < t.size(); right++) {
    for (int i = 0; i < start.size(); i++) {
      if (s[start[i] + right] == t[right]) continue;
      swap(start[i], start.back());
      start.pop_back();
      i--;
    }
    for (const int pos : start) {
      if (find_back(s, t.substr(right + 1), pos + right - 1)) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}