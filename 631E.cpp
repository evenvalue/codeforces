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

class LineContainer {
  struct Line {
    int64 m, c;
    mutable int64 p;
    bool operator<(int64 x) const {
      return p < x;
    }
    bool operator<(const Line &other) const {
      return (m == other.m ? c < other.c : m < other.m);
    }
  };

  using Lines = set<Line, std::less<>>;
  const int64 kInf = 1e18;
  Lines lines;

  static int64 div(int64 a, int64 b) {
    return a / b - ((a ^ b) < 0 and a % b);
  }

  int64 update(const Line &a, const Line &b) const {
    if (a.m == b.m) {
      a.p = (a.c > b.c) ? kInf : -kInf;
    } else {
      a.p = div(b.c - a.c, a.m - b.m);
    }
    return a.p;
  }

  bool ends(auto it) {
    return (it == lines.begin() or it == lines.end());
  }

public:
  void add(int64 slope, int64 intercept) {
    auto [y, _] = lines.insert(Line{slope, intercept, kInf});

    // try deleting next lines
    auto nxt = next(y);
    while (not ends(nxt) and update(*y, *nxt) >= nxt->p) {
      nxt = lines.erase(nxt);
    }

    // try deleting current line.
    if (not ends(y) and update(*prev(y), *y) >= y->p) {
      update(*prev(y), *lines.erase(y));
      return;
    }

    // try deleting previous lines.
    while (not ends(y) and update(*prev(y), *y) >= y->p) {
      lines.erase(prev(y));
    }
  }

  [[nodiscard]] int64 query(int64 x) const {
    const Line l = *lines.lower_bound(x);
    return (l.m * x) + (l.c);
  }

  [[nodiscard]] auto size() const {
    return lines.size();
  }
};

inline void solution() {
  const int n = read::Int();
  vector<int> a(n + 1);
  vector<int64> sum(n + 1);
  int64 ans = 0;

  auto cost = [&](const int i) -> int64 {
    return a[i] * 1LL * i;
  };

  for (int i = 1; i <= n; i++) {
    a[i] = read::Int();
    sum[i] = sum[i - 1] + a[i];
    ans += cost(i);
  }
  int64 delta = 0;
  LineContainer front;
  for (int i = n; i > 0; i--) {
    front.add(i, -sum[i]);
    delta = max(delta, front.query(a[i]) + sum[i] - cost(i));
  }
  LineContainer back;
  for (int i = 1; i <= n; i++) {
    back.add(i, -sum[i - 1]);
    delta = max(delta, sum[i - 1] - cost(i) + back.query(a[i]));
  }
  cout << ans + delta << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}