#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

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

int count_primes(int x, const vector<int> &primes) {
  int cnt = 0;
  for (const int p : primes) {
    if (p * p > x) break;
    while (x % p == 0) {
      cnt++;
      x /= p;
    }
  }
  cnt += (x > 1);
  return cnt;
}

bool solve(const vector<int> &primes) {
  int a, b, turns;
  cin >> a >> b >> turns;
  if (a == b and turns == 1) return false;
  const int g = gcd(a, b);
  int at_least = (a > g) + (b > g);
  int at_most = count_primes(a, primes) + count_primes(b, primes);
  return (at_least <= turns and turns <= at_most);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const vector<int> primes = sieve(4e4);

  int t = 1;
  cin >> t;
  while (t--) {
    cout << (solve(primes) ? "YES" : "NO") << '\n';
  }
}