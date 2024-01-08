#include <bits/stdc++.h>
using namespace std;

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

int make_mask(const int i = 0, const int j = 0, const int k = 0) {
  int mask = 0;
  mask |= (1 << i);
  mask |= (1 << j);
  mask |= (1 << k);
  return mask;
}

inline void solution() {
  const int n = read::Int();
  const int m = read::Int();

  vector<pair<int, int>> pairs(m);
  for (auto &[x, y] : pairs) {
    x = read::Int();
    y = read::Int();
  }

  auto print = [](const vector<int> &ans) {
    cout << ans.size() << '\n';
    for (const int x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  };

  if (n >= 20) {
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    print(ans);
    return;
  }

  vector<int> ans;
  auto construct = [&](const int final) -> bool {
    int cur = 0, press = 0;

    for (int i = 1; i <= n; i++) {
      if ((final - cur) & (1 << i)) {
        press |= (1 << i);

        for (int j = i; j <= n; j += i) {
          cur ^= (1 << j);
        }
      }
    }

    for (const auto [x, y] : pairs) {
      const bool press_x = press & (1 << x);
      const bool press_y = press & (1 << y);
      if (press_x and not press_y) return false;
    }

    for (int i = 1; i <= n; i++) {
      if (press & (1 << i)) ans.push_back(i);
    }

    print(ans);
    return true;
  };

  for (int i = 1; i <= n and n >= 5; i++) {
    if (construct(make_mask(i))) {
      return;
    }
    for (int j = i + 1; j <= n and n >= 10; j++) {
      if (construct(make_mask(i, j))) {
        return;
      }
      for (int k = j + 1; k <= n and n >= 15; k++) {
        if (construct(make_mask(i, j, k))) {
          return;
        }
      }
    }
  }

  cout << -1 << '\n';
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