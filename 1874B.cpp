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

constexpr array<int, 10> pow5 = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125};
constexpr int kSize = 8;
constexpr int kMaxNodes = pow5[kSize];

template<int Size>
struct Quinary {
  int x;
  vector<int> number;

  explicit Quinary(int n) : x(n), number(Size, 0) {
    for (int i = 0; i < Size; i++) {
      number[i] = n % 5;
      n /= 5;
    }
    assert(n == 0);
  }

  int hash() {
    x = 0;
    for (int i = 0; i < Size; i++) {
      assert(0 <= number[i] and number[i] < 5);
      x += pow5[i] * number[i];
    }
    return x;
  }

  int &operator[](const int i) {
    return number[i];
  }
};

template<int Size, class F = function<int(int, int, int)>>
Quinary<Size> operate(Quinary<Size> cur, const F &op) {
  Quinary<Size> ans(0);
  for (int i = 0; i < Size; i++) {
    if (cur[i] == 0) continue;

    const int x = (i & 4) / 4;
    const int y = (i & 2) / 2;
    const int m = (i & 1) / 1;

    const int change = op(x, y, m);

    if (ans[change] == 0 or ans[change] == cur[i]) {
      ans[change] = cur[i];
    } else {
      return Quinary<Size>(0);
    }
  }
  ans.hash();
  return ans;
}

inline void solution(const vector<int> &dist) {
  const int a = Read::Int();
  const int b = Read::Int();
  const int c = Read::Int();
  const int d = Read::Int();
  const int m = Read::Int();

  Quinary<kSize> q(0);
  for (int bit = 30; bit >= 0; bit--) {
    const int x = (a & (1 << bit)) / (1 << bit);
    const int y = (b & (1 << bit)) / (1 << bit);
    const int k = (m & (1 << bit)) / (1 << bit);

    const int final_x = (c & (1 << bit)) / (1 << bit);
    const int final_y = (d & (1 << bit)) / (1 << bit);

    const int change = x * 4 + y * 2 + k;
    const int to = final_x * 2 + final_y + 1;

    if (q[change] == 0 or q[change] == to) {
      q[change] = to;
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  const int x = q.hash();
  cout << (dist[x] == kInf ? -1 : dist[x]) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  constexpr auto operate_and = [](const int x, const int y, const int m) {
    return (x & y) * 4 + y * 2 + m;
  };
  constexpr auto operate_or = [](const int x, const int y, const int m) {
    return (x | y) * 4 + y * 2 + m;
  };
  constexpr auto operate_xor_x = [](const int x, const int y, const int m) {
    return x * 4 + (x ^ y) * 2 + m;
  };
  constexpr auto operate_xor_m = [](const int x, const int y, const int m) {
    return x * 4 + (m ^ y) * 2 + m;
  };

  vector<vector<int>> g(kMaxNodes);
  auto add_edge = [&](const Quinary<kSize> &p, const Quinary<kSize> &q) {
    g[q.x].push_back(p.x);
  };

  vector<int> dist(kMaxNodes, kInf);
  queue<int> q;

  for (int x = 1; x < kMaxNodes; x++) {
    Quinary<kSize> cur(x);

    add_edge(cur, operate(cur, operate_and));
    add_edge(cur, operate(cur, operate_or));
    add_edge(cur, operate(cur, operate_xor_x));
    add_edge(cur, operate(cur, operate_xor_m));

    bool ending = true;
    for (int i = 0; i < kSize; i++) {
      if (cur[i] != 0 and cur[i] != (i / 2) + 1) {
        ending = false;
        break;
      }
    }

    if (ending) {
      dist[x] = 0;
      q.push(x);
    }
  }

  while (not q.empty()) {
    const int x = q.front();
    for (const int y : g[x]) {
      if (dist[y] == kInf) {
        dist[y] = dist[x] + 1;
        q.push(y);
      }
    }
    q.pop();
  }

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution(dist);
  }
}