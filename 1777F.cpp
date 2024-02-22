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

namespace Read {
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
}//namespace Read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;
constexpr int kBits = 32;

class Trie {
  static constexpr int AlphaSize = 2;
  vector<vector<int>> t;
  vector<bool> terminal;

  int add_node() {
    const int x = t.size();
    t.emplace_back(AlphaSize, -1);
    terminal.push_back(false);
    return x;
  }

  int dfs(const int x, const int i, const int qry) {
    if (terminal[x]) return 0;
    const int bit = ((qry & (1 << i)) ? 1 : 0);
    if (t[x][1 - bit] != -1) {
      return dfs(t[x][1 - bit], i - 1, qry) + (1 << i) * (1 - bit);
    } else {
      return dfs(t[x][bit], i - 1, qry) + (1 << i) * bit;
    }
  }

public:
  Trie() {
    add_node();
  }

  void add(const int x) {
    int node = 0;
    for (int i = kBits - 1; i >= 0; i--) {
      const int bit = ((x & (1 << i)) ? 1 : 0);
      if (t[node][bit] == -1) t[node][bit] = add_node();
      node = t[node][bit];
    }
    terminal[node] = true;
  }

  int query(const int x) {
    return dfs(0, kBits - 1, x) ^ x;
  }
};

inline void solution() {
  const int n = Read::Int();
  const vector<int> a = Read::Vec<int>(n);

  function<int(int, int)> dnc = [&](const int L, const int R) {
    if (L == R) return 0;

    const int mid = (L + R) / 2;
    const int left_part = dnc(L, mid);
    const int right_part = dnc(mid + 1, R);
    int cur_part = 0;

    Trie left;
    left.add(0);

    for (int l = mid, r = mid + 1, xor_l = 0, xor_r = 0, mx_r = 0; r <= R; r++) {
      xor_r ^= a[r];
      mx_r = max(mx_r, a[r]);

      while (L <= l and a[l] <= mx_r) {
        xor_l ^= a[l];
        left.add(xor_l);
        l--;
      }

      cur_part = max(cur_part, left.query(mx_r ^ xor_r));
    }

    Trie right;
    right.add(0);

    for (int l = mid, r = mid + 1, xor_l = 0, xor_r = 0, mx_l = 0; l >= L; l--) {
      xor_l ^= a[l];
      mx_l = max(mx_l, a[l]);

      while (r <= R and a[r] <= mx_l) {
        xor_r ^= a[r];
        right.add(xor_r);
        r++;
      }

      cur_part = max(cur_part, right.query(mx_l ^ xor_l));
    }

    return max({cur_part, left_part, right_part});
  };

  cout << dnc(0, n - 1) << '\n';
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