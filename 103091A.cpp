#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kInf = 1e9 + 10;

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] ^ a[i];
  }
  vector<int64> mx(n + 1);
  vector<int64> mn(n + 1);
  for (int i = 1; i <= n; i++) {
    mn[i] = kInf;
    for (int s = 1; s <= i; s++) {
      mx[i] = max(mx[i], (pref[i] ^ pref[s - 1]) + mx[s - 1]);
      mn[i] = min(mn[i], (pref[i] ^ pref[s - 1]) + mn[s - 1]);
    }
  }
  cout << mx[n] - mn[n] << "\n";
}