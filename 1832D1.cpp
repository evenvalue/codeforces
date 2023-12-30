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

class Small {
  const int n;
  vector<int> a;
  vector<int> inc;
  vector<int> smallest;

public:
  explicit Small(const vector<int> &v) : n(v.size()), a(v) {
    sort(a.begin(), a.end());
    inc = a;
    for (int i = 0; i < n; i++) {
      inc[i] -= i;
    }
    smallest.resize(n);
    smallest[0] = inc[0];
    for (int i = 1; i < n; i++) {
      smallest[i] = min(smallest[i - 1], inc[i]);
    }
  }

  int mn(const int k) {
    if (k == n) return smallest[k - 1] + k;
    return min(smallest[k - 1] + k, a[k]);
  }
};

class Even {
  const int n;
  vector<int> a;
  int req = 0;

  int formula(int least, int dec) const {
    if (dec <= req) return least;
    return least - ((dec - req + n - 1) / n);
  }

public:
  explicit Even(const vector<int> &v) : n(v.size()), a(v) {
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      a[i] -= i;
    }
    sort(a.begin(), a.end());
    for (const int x : a) {
      req += x - a[0];
    }
  }

  int mn(const int add, const int dec) {
    return add + formula(a[0], dec);
  }
};

class Odd {
  const int n;
  vector<int> a;

  int smallest = -1;
  int unchanged = -1;
  int req = 0;

  int formula(int least, int dec) {
    if (dec <= req) return least;
    return least - ((dec - req + n - 1) / n);
  }

public:
  explicit Odd(const vector<int> &v) : n(v.size()), a(v) {
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      a[i] -= i;
    }
    unchanged = a.back();
    sort(a.begin(), a.end() - 1);
    smallest = a[0];

    for (int i = 0; i < n - 1; i++) {
      req += a[i] - a[0];
    }
  }

  int mn(const int add, const int dec) {
    const int least = smallest + add;
    if (least <= unchanged) {
      req += unchanged - least;
      const int ans = formula(least, dec);
      req -= unchanged - least;
      return ans;
    } else {
      req += (least - unchanged) * (n - 1);
      const int ans = formula(unchanged, dec);
      req -= (least - unchanged) * (n - 1);
      return ans;
    }
  }
};

inline void solution() {
  const int n = read::Int();
  const int q = read::Int();

  vector<int> a = read::Vec<int>(n);

  Small small(a);
  Even even(a);
  Odd odd(a);

  for (int qry = 0; qry < q; qry++) {
    const int k = read::Int();
    if (k <= n) {
      cout << small.mn(k) << ' ';
    } else if ((k & 1) == (n & 1)) {
      cout << even.mn(k, (k - n) / 2) << ' ';
    } else {
      cout << odd.mn(k, (k - n + 1) / 2) << ' ';
    }
  }
  cout << '\n';
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