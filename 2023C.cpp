#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
T read() {
  T x;
  cin >> x;
  return x;
}

template<typename T1, typename T2>
pair<T1, T2> read_pair() {
  pair<T1, T2> p;
  cin >> p.first;
  cin >> p.second;
  return p;
}

template<typename T>
vector<T> read_vec(const int n, const int index = 0) {
  vector<T> v(n + index);
  for (int i = index; i < n + index; i++) {
    v[i] = read<T>();
  }
  return v;
}

template<typename T>
vector<vector<T>> read_vec_vec(const int n, const int m, const int index_n = 0, const int index_m = 0) {
  vector<vector<T>> grid(n + index_n);
  for (int i = index_n; i < n + index_n; i++) {
    grid[i] = read_vec<T>(m, index_m);
  }
  return grid;
}

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[kMaxN];

int64_t modmul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}

void init() {
  base_pow[0] = 1;
  for (int i = 1; i < kMaxN; i++) {
    base_pow[i] = modmul(base_pow[i - 1], base);
  }
}

struct PolyHash {
  vector<int64_t> pref;

  PolyHash() = default;

  template<typename T>
  explicit PolyHash(const vector<T> &ar) {
    if (!base_pow[0]) init();

    int n = ar.size();
    assert(n < kMaxN);
    pref.resize(n + 3, 0);

    for (int i = 1; i <= n; i++) {
      pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
      if (pref[i] >= mod) pref[i] -= mod;
    }
  }

  uint64_t get_hash(int l, int r) {
    int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
    return h < 0 ? h + mod : h;
  }
};

vector<int> assign(const int n, const int k) {
  const int m = read<int>();
  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++) {
    const int x = read<int>() - 1;
    const int y = read<int>() - 1;
    g[x].push_back(y);
  }

  vector<int> a(n, -1);

  function<void(int)> dfs = [&](const int x) {
    for (const int y : g[x]) {
      if (a[y] != -1) continue;
      a[y] = (a[x] + 1) % k;
      dfs(y);
    }
  };

  a[0] = 0;
  dfs(0);

  return a;
}

inline void solution() {
  const int n = read<int>();
  const int k = read<int>();

  auto a = read_vec<int>(n);
  auto p = assign(n, k);

  auto b = read_vec<int>(n);
  auto q = assign(n, k);

  array<vector<int>, 2> edge_a;
  array<vector<int>, 2> edge_b;

  for (int x = 0; x < n; x++) {
    edge_a[a[x]].push_back(p[x]);
    edge_b[b[x]].push_back(q[x]);
  }

  if (edge_a[0].size() != edge_b[1].size()) {
    cout << "NO\n";
    return;
  }

  if (edge_a[0].empty() or edge_a[1].empty()) {
    cout << "YES\n";
    return;
  }

  for (int &x : edge_b[1]) {
    x += 2;
    x %= k;
  }

  array<vector<int>, 2> freq_a, freq_b;
  for (int i = 0; i < 2; i++) {
    freq_a[i] = vector<int>(k);
    for (const int x : edge_a[i]) {
      freq_a[i][x]++;
    }
  }

  for (int i = 0; i < 2; i++) {
    freq_b[i] = vector<int>(2 * k);
    for (const int x : edge_b[i]) {
      freq_b[i][x]++;
      freq_b[i][x + k]++;
    }
  }

  PolyHash pa0(freq_a[0]);
  PolyHash pa1(freq_a[1]);
  PolyHash pb0(freq_b[0]);
  PolyHash pb1(freq_b[1]);

  for (int c = 0; c < k; c++) {
    const bool b1 = pa0.get_hash(0, k - 1) == pb1.get_hash(c, k + c - 1);
    const bool b2 = pa1.get_hash(0, k - 1) == pb0.get_hash(c, k + c - 1);
    if (b1 and b2) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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