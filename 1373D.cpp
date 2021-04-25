#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int64 kadane(const vector<int> &a) {
  int64 cur = 0;
  int64 gmax = 0;
  for (const int x : a) {
    cur = max(x * 1LL, cur + x);
    gmax = max(gmax, cur);
  }
  return gmax;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    int64 sum = 0;
    for (int i = 0; i < n; i += 2) {
      sum += a[i];
    }
    vector<int> even(n / 2);
    vector<int> odd((n - 1) / 2);
    for (int i = 0; i < even.size(); i++) {
      even[i] = a[2 * i + 1] - a[2 * i];
    }
    for (int i = 0; i < odd.size(); i++) {
      odd[i] = a[(2 * i) + 1] - a[2 * (i + 1)];
    }
    cout << sum + max(kadane(even), kadane(odd)) << "\n";
  }
}