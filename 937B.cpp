#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

vector<int> sieve(const int n) {
  vector<int> primes;
  primes.reserve(4203);
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (not is_prime[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  return primes;
}

int smallest_prime(const int x, const vector<int> &primes) {
  for (const int p : primes) {
    if (x % p) continue;
    return p;
  }
  return x;
}

void solve(const vector<int> &primes) {
  int x, y;
  cin >> x >> y;
  int ans = -1;
  for (int num = y; num >= max(2, y - 300); num--) {
    if (const int p = smallest_prime(num, primes); p > x) {
      ans = num;
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const vector<int> primes = sieve(4e4);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve(primes);
  }
}