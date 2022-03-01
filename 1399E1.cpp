#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...)
#endif

using int64 = int64_t;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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


template<typename T, class F = function<bool(const T&, const T&)>>
class Heap {
  vector<T> heap;
  const F Cmp;

  int parent(const int x) {
    if (x == 0) assert(false);
    return (x - 1) / 2;
  }

  int left(const int x) {
    const int l = 2 * x + 1;
    if (l >= heap.size()) assert(false);
    return l;
  }

  int right(const int x) {
    const int r = 2 * (x + 1);
    if (r >= heap.size()) assert(false);
    return r;
  }

  bool leaf(const int x) {
    return (2 * x + 1 >= heap.size());
  }

  bool singleChild(const int x) {
    return (not leaf(x) and 2 * (x + 1) == heap.size());
  }

public:
  explicit Heap(F f) : Cmp(std::move(f)) {}

  void push(const T &x) {
    heap.push_back(x);
    int cur = heap.size() - 1;
    while (cur) {
      const int par = parent(cur);
      if (Cmp(heap[par], heap[cur])) break;
      swap(heap[cur], heap[par]);
      cur = par;
    }
  }

  T pop() {
    assert(not heap.empty());
    const T top = heap[0];
    if (heap.size() == 1) {
      heap.pop_back();
      return top;
    }
    swap(heap[0], heap.back());
    heap.pop_back();
    int x = 0;
    while (not leaf(x)) {
      if (singleChild(x)) {
        if (const int l = left(x); Cmp(heap[l], heap[x])) {
          swap(heap[x], heap[l]);
        }
        break;
      } else {
        const int l = left(x), r = right(x);
        int y = (Cmp(heap[l], heap[r]) ? l : r);
        if (Cmp(heap[x], heap[y])) break;
        swap(heap[x], heap[y]);
        x = y;
      }
    }
    return top;
  }

  T top() const {
    return heap[0];
  }

  bool empty() const {
    return (heap.empty());
  }
};

struct edge {
  int x, y, w;
  int leaves;
  int64 contrib;
};

void solution() {
  const int n = read::Int();
  int64 s = read::Int64();
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    const int x = read::Int() - 1, y = read::Int() - 1, w = read::Int();
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  vector<edge> edges(n);

  function<int(int, int)> dfs = [&](const int x, const int p) {
    int leaves = 0;
    for (const auto &[y, w] : g[x]) {
      if (y == p) continue;
      const int leavesY = dfs(y, x);
      edges.push_back({x, y, w, leavesY, 0});
      leaves += leavesY;
    }
    return (leaves + (leaves == 0));
  };

  dfs(0, -1);

  int64 cur = 0;

  auto reduction = [](const edge &e) {
    return e.contrib - ((e.w / 2) * 1LL * e.leaves);
  };

  Heap<edge> heap([&](const edge &first, const edge &second) {
    return reduction(first) > reduction(second);
  });

  for (edge &e : edges) {
    e.contrib = e.leaves * 1LL * e.w;
    heap.push(e);
    cur += e.contrib;
  }

  int steps = 0;
  while (cur > s) {
    edge e = heap.pop();
    const int64 reduce = reduction(e);
    cur -= reduce, e.contrib -= reduce;
    e.w >>= 1;
    heap.push(e);
    steps++;
  }

  cout << steps << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}