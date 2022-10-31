#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
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


vector<int> prime_factors(const int n, const vector<int> &min_factor) {
  vector<int> primes;
  for (int x = n; x != 1; x /= min_factor[x]) {
    primes.push_back(min_factor[x]);
  }
  primes.erase(std::unique(primes.begin(), primes.end()), primes.end());
  return primes;
}

inline void solution(const vector<int> &min_factor) {
  const int n = read::Int();
  const vector<int> &a = read::Vec<int>(n);

  vector<int> primes;
  for (const int x : a) {
    const vector<int> &v = prime_factors(x, min_factor);
    primes.insert(primes.end(), v.begin(), v.end());
  }

  sort(primes.begin(), primes.end());

  const int q = read::Int();
  for (int query = 0; query < q; query++) {
    const int l = read::Int(), r = read::Int();
    cout << distance(lower_bound(primes.begin(), primes.end(), l),
                     upper_bound(primes.begin(), primes.end(), r));
    cout << '\n';
  }
}

vector<int> sieve(const int n) {
  vector<int> min_factor(n);
  iota(min_factor.begin(), min_factor.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (min_factor[i] != i) continue;
    for (int64 j = i * 1LL * i; j <= n; j += i) {
      min_factor[j] = min(min_factor[j], i);
    }
  }
  return min_factor;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  const vector<int> min_factor = sieve(1e7 + 10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution(min_factor);
  }
}