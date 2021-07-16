#include <algorithm>
#include <array>
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
    for (int64 j = (int64)i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  return primes;
}

vector<pair<int64, int>> prime_factorize(int64 x, const vector<int> &primes) {
  vector<pair<int64, int>> pfacts;
  for (const int p : primes) {
    if ((int64)p * p > x) break;
    if (x % p) continue;
    pfacts.emplace_back(p, 0);
    while (x % p == 0) {
      pfacts.back().second++;
      x /= p;
    }
  }

  if (x) pfacts.emplace_back(x, 1);
  return pfacts;
}

void solve(const vector<int> &primes) {
  int64 n;
  cin >> n;
  const vector<pair<int64, int>> pfacts = prime_factorize(n, primes);
  int64 ans = 1;
  pair<int64, int> prime = {0, 0};
  for (const pair<int64, int> &p : pfacts) {
    if (p.second <= prime.second) {
      for (int i = 0; i < p.second; i++) {
        ans *= p.first;
      }
    } else {
      for (int i = 0; i < prime.second; i++) {
        ans *= prime.first;
      }
      prime = p;
    }
  }
  cout << prime.second << '\n';
  for (int i = 0; i < prime.second - 1; i++) {
    cout << prime.first << ' ';
  }
  cout << prime.first * ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> primes = sieve(2e5);

  int t = 1;
  cin >> t;
  while (t--) {
    solve(primes);
    cout << '\n';
  }
}