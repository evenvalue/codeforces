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

int randint(const int l, const int r) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(l, r);
  return distrib(gen);
}

template<typename T>
class CoordinateCompression {
  bool sorted = false;
  vector<T> v;

public:
  void add(const T &x) {
    v.push_back(x);
  }

  void compress() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sorted = true;
  }

  int get(const int x) {
    if (not sorted) assert(false);
    return distance(v.begin(), lower_bound(v.begin(), v.end(), x));
  }

  int size() {
    return v.size();
  }
};

struct Lecture {
  pair<int, int> a;
  pair<int, int> b;
};

vector<int> isect(const vector<vector<int>> &in, const vector<vector<int>> &out, const vector<int> &val) {
  const int n = val.size();
  const int k = in.size();

  int started = 0;
  int ended = 0;

  vector<int> ans(n);
  for (int i = 0; i < k; i++) {
    for (const int x : in[i]) {
      started ^= val[x];
      ans[x] ^= ended;
    }
    for (const int x : out[i]) {
      ended ^= val[x];
      ans[x] ^= started;
    }
  }

  return ans;
}

inline void solution() {
  const int n = read<int>();
  vector<int> val(n);
  for (int &x : val) x = randint(1, 2e9);

  CoordinateCompression<int> cc_a;
  CoordinateCompression<int> cc_b;

  vector<Lecture> lectures(n);
  for (auto &[a, b] : lectures) {
    cc_a.add(a.first = read<int>());
    cc_a.add(a.second = read<int>());
    cc_b.add(b.first = read<int>());
    cc_b.add(b.second = read<int>());
  }

  cc_a.compress();
  cc_b.compress();

  const int ka = cc_a.size();
  const int kb = cc_b.size();

  vector<vector<int>> in_a(ka), out_a(ka);
  vector<vector<int>> in_b(kb), out_b(kb);
  for (int i = 0; i < n; i++) {
    auto &[a, b] = lectures[i];
    auto &[la, ra] = a;
    auto &[lb, rb] = b;
    la = cc_a.get(la), ra = cc_a.get(ra);
    lb = cc_b.get(lb), rb = cc_b.get(rb);
    in_a[la].push_back(i), out_a[ra].push_back(i);
    in_b[lb].push_back(i), out_b[rb].push_back(i);
  }

  cout << (isect(in_a, out_a, val) == isect(in_b, out_b, val) ? "YES" : "NO") << '\n';
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