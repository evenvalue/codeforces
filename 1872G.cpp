#include <bits/stdc++.h>
using namespace std;

#define int long long

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

inline void solution() {
  const int n = read<int>();

  vector<int> a(n + 2, 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (count(a.begin(), a.end(), 1) == n + 2) {
    cout << 1 << ' ' << 1 << '\n';
    return;
  }

  int l = 0;
  while (a[l] == 1) l++;

  int r = n;
  while (a[r] == 1) r--;

  int64 prod = 1;
  for (int i = l; i <= r; i++) {
    if (LLONG_MAX / prod < a[i]) {
      cout << l << ' ' << r << '\n';
      return;
    }
    prod *= a[i];
  }

  vector<int> sum(n + 2);
  vector<int> pro(n + 2, 1);

  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
    pro[i] = pro[i - 1] * a[i];
  }

  vector<int> non_one;
  for (int i = l; i <= r; i++) {
    if (a[i] == 1) continue;
    non_one.push_back(i);
  }

  int64 ans = 0;
  int l_ans = 0, r_ans = 0;

  const int k = non_one.size();
  for (int i = 0; i < k; i++) {
    for (int j = i; j < k; j++) {
      const int left = non_one[i];
      const int right = non_one[j];
      int local = sum[left - 1] + (pro[right] / pro[left - 1]) + (sum[n] - sum[right]);
      if (local > ans) {
        l_ans = left;
        r_ans = right;
        ans = local;
      }
    }
  }

  cout << l_ans << ' ' << r_ans << '\n';
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