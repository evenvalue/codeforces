#include <iostream>
#include <array>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kMod = 1e9 + 7;
  const int kMaxN = 1e5 + 10;

  int q, k;
  cin >> q >> k;
  array<int, kMaxN> ways = {};
  ways[0] = 1;
  for (int i = 1; i < kMaxN; i++) {
    ways[i] = ((i >= k ? ways[i - k] : 0) + ways[i - 1]) % kMod;
  }
  array<int, kMaxN> pref = {};
  pref[0] = ways[0];
  for (int i = 1; i < kMaxN; i++) {
    pref[i] = (pref[i - 1] + ways[i]) % kMod;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (pref[r] - pref[l - 1] + kMod) % kMod << '\n';
  }
}