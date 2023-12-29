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

inline vector<int> max_problems(const vector<int> &time, const int64 max_time) {
  const int n = time.size();

  vector<int> best(n + 1);
  max_heap<int> heap;

  for (int64 i = 0, sum = 0; i < n; i++) {
    sum += time[i];
    heap.push(time[i]);
    if (sum > max_time) {
      sum -= heap.top();
      heap.pop();
    }
    best[i + 1] = heap.size();
  }

  return best;
}

inline void solution() {
  const int n = read::Int();
  const int k = read::Int();

  vector<int> pref_time = read::Vec<int>(n);
  vector<int> suff_time = pref_time;
  reverse(suff_time.begin(), suff_time.end());

  auto check = [&](const int64 max_time) -> bool {
    const vector<int> &prefix = max_problems(pref_time, max_time);
    const vector<int> &suffix = max_problems(suff_time, max_time);
    for (int i = 0; i <= n; i++) {
      if (prefix[i] + suffix[n - i] >= k) {
        return true;
      }
    }
    return false;
  };

  const int64 sum = accumulate(pref_time.begin(), pref_time.end(), 0LL);

  int64 lo = 0, hi = sum;
  while (lo < hi) {
    const int64 mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << '\n';
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