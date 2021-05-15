#include <iostream>
using namespace std;

int ask(const int l, const int r) {
  cout << "? " << l << " " << r << endl;
  int ones;
  cin >> ones;
  return r - l + 1 - ones;
}

void say(const int x) {
  cout << "! " << x << endl;
}

void bin_search(const int n, int k) {
  int lo = 1, hi = n;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    const int zeros = ask(lo, mid);
    if (k <= zeros) {
      hi = mid;
    } else {
      k -= zeros;
      lo = mid + 1;
    }
  }
  say(lo);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, t;
  cin >> n >> t;
  while (t--) {
    int k;
    cin >> k;
    bin_search(n, k);
  }
}