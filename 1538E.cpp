#include <algorithm>
#include <array>
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

int64 count(const string &s, const string &t = "haha") {
  int64 cnt = 0;
  for (int i = t.size(); i <= s.size(); i++) {
    cnt += (s.substr(i - t.size(), t.size()) == t);
  }
  return cnt;
}

string pref(const string &s) {
  if (s.size() <= 3) return s;
  return s.substr(0, 3);
}

string suff(const string &s) {
  const int n = s.size();
  if (n <= 3) return s;
  return s.substr(n - 3, 3);
}

struct word {
  int64 cnt;
  string s;

  word operator+(const word &other) const {
    word ret{};
    ret.cnt = cnt + other.cnt + count(suff(s) + pref(other.s));
    ret.s = pref(s) + suff(other.s);
    return ret;
  }
};

void solve() {
  map<string, word> assign;
  int q;
  cin >> q;
  string s;
  while (q--) {
    string op;
    cin >> s >> op;
    if (op == "=") {
      string a, plus, b;
      cin >> a >> plus >> b;
      assign[s] = assign[a] + assign[b];
    } else {
      string val;
      cin >> val;
      assign[s] = {count(val), val};
    }
  }
  cout << assign[s].cnt << '\n';
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