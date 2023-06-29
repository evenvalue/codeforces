#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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

struct edge {
  int x;
  int y;
};

inline void solution() {
  const int n = read::Int();
  const string parity = read::String();

  const int odd = (int) count(parity.begin(), parity.end(), '1');
  if (odd == 0 or odd % 2 == 1) {
    cout << "NO" << '\n';
    return;
  }

  const int shift = (int) (find(parity.begin(), parity.end(), '1') - parity.begin()) + 1;

  string s(n, '-');
  for (int i = 0; i < n; i++) {
    s[(i - shift + n) % n] = parity[i];
  }

  assert(s.back() == '1');

  vector<vector<int>> segments = {{}};
  for (int i = 1; i < n; i++) {
    segments.back().push_back(i);
    if (s[i] == '1') {
      segments.emplace_back();
    }
  }

  assert(segments.back().empty());
  segments.pop_back();

  vector<edge> edges;
  for (const vector<int> &segment : segments) {
    edges.push_back({0, segment[0]});
    for (int i = 0; i < (int) (segment.size()) - 1; i++) {
      edges.push_back({segment[i], segment[i + 1]});
    }
  }

  cout << "YES" << '\n';
  for (auto [x, y] : edges) {
    x = ((x + shift) % n) + 1;
    y = ((y + shift) % n) + 1;
    cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}