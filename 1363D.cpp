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

int ask(const vector<int> &a) {
  cout << "? ";
  cout << a.size();
  for (const int x : a) {
    cout << ' ' << x + 1;
  }
  cout << endl;
  return read<int>();
}

int ask(const int l, const int r) {
  const int len = r - l + 1;
  vector<int> a(len);
  iota(a.begin(), a.end(), l);
  return ask(a);
}

inline void solution() {
  const auto n = read<int>();
  const auto k = read<int>();
  vector<vector<int>> subsets(k);
  for (auto &subset : subsets) {
    subset = read_vec<int>(read<int>());
    sort(subset.begin(), subset.end());
    for (int &x : subset) x--;
  }

  const int mx = ask(0, n - 1);
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    if (ask(lo, mid) == mx) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  vector<int> ans(k);
  for (int i = 0; i < k; i++) {
    const vector<int> &a = subsets[i];
    const auto it = find(a.begin(), a.end(), lo);
    if (it == a.end()) {
      ans[i] = mx;
    } else {
      vector<bool> seen(n);
      for (const int x : a) seen[x] = true;
      vector<int> qry;
      for (int j = 0; j < n; j++) {
        if (not seen[j]) qry.push_back(j);
      }
      ans[i] = ask(qry);
    }
  }

  cout << "!";
  for (const int x : ans) {
    cout << ' ' << x;
  }
  cout << endl;

  assert(read<string>() == "Correct");
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