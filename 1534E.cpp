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

int ask(const vector<int> &a) {
  cout << "? ";
  for (const int x : a) {
    cout << x << ' ';
  }
  cout << endl;
  return read::Int();
}

void say(const int x) {
  cout << "! " << x << endl;
}

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  auto nbrs = [&](const int ones) -> vector<int> {
    const int zeros = n - ones;

    vector<int> nbr;
    for (int x = 0; x <= k; x++) {
      if (x > ones) continue;
      if (k - x > zeros) continue;
      nbr.push_back(ones - x + (k - x));
    }

    return nbr;
  };

  vector<vector<int>> g(n + 1);
  for (int x = 0; x < n; x++) {
    g[x] = nbrs(x);
  }

  vector<int> dist(n + 1, kInf);
  vector<int> p(n + 1, -1);

  queue<int> q;
  dist[0] = 0;
  q.push(0);
  while (not q.empty()) {
    const int x = q.front();
    for (const int y : g[x]) {
      if (dist[y] != kInf) continue;
      p[y] = x;
      dist[y] = dist[x] + 1;
      q.push(y);
    }
    q.pop();
  }

  if (dist[n] == kInf) {
    cout << -1 << '\n';
    return;
  }

  vector<int> go(n + 1);
  for (int i = n; i != 0; i = p[i]) {
    go[p[i]] = i;
  }

  vector<int> ones;
  vector<int> zero(n);
  iota(zero.begin(), zero.end(), 1);

  auto next_state = [&](const int x) -> vector<int> {
    const int pick = (ones.size() + k - x) / 2;

    vector<int> choose(k);
    for (int i = 0; i < pick; i++) {
      const int last = ones.back();
      choose[i] = last;
      ones.pop_back();
    }

    for (int i = pick; i < k; i++) {
      const int last = zero.back();
      choose[i] = last;
      zero.pop_back();
    }

    for (int i = 0; i < pick; i++) {
      zero.push_back(choose[i]);
    }

    for (int i = pick; i < k; i++) {
      ones.push_back(choose[i]);
    }

    return choose;
  };

  int ans = 0;
  for (int i = 0; i != n; i = go[i]) {
    ans ^= ask(next_state(go[i]));
  }

  say(ans);
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