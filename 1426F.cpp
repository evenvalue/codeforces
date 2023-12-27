#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef evenvalue
  #include "debug.h"
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

namespace read {
int Int() {
  int x;
  cin >> x;
  return x;
}
int64 Int64() {
  int64 x;
  cin >> x;
  return x;
}
char Char() {
  char c;
  cin >> c;
  return c;
}
string String() {
  string s;
  cin >> s;
  return s;
}
double Double() {
  return stod(String());
}
ld LongDouble() {
  return stold(String());
}
template<typename T1, typename T2>
pair<T1, T2> Pair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> Vec(const int n) {
  vector<T> v(n);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> VecVec(const int n, const int m) {
  vector<vector<T>> v(n);
  for (vector<T> &vec : v) {
    vec = Vec<T>(m);
  }
  return v;
}
}//namespace read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

inline void solution() {
  const int n = read::Int();
  string s = " " + read::String();

  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == '?');
  }

  vector<int> suff(n + 2);
  for (int i = n; i >= 0; i--) {
    suff[i] = suff[i + 1] + (s[i] == '?');
  }

  vector<int> pow3(n + 1);
  pow3[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow3[i] = (pow3[i - 1] * 3) % kMod;
  }

  int a = 0;
  int c = count(s.begin(), s.end(), 'c');

  auto formula = [&](const int letter, const int three) -> int {
    if (three == 0) return letter;
    const int part1 = (letter * pow3[three]) % kMod;
    const int part2 = (three * pow3[three - 1]) % kMod;
    return (part1 + part2) % kMod;
  };

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    c -= (s[i] == 'c');
    if (s[i] == 'b' or s[i] == '?') {
      ans += formula(a, pref[i - 1]) * formula(c, suff[i + 1]);
      ans %= kMod;
    }
    a += (s[i] == 'a');
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}