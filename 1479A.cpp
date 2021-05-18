#include <iostream>
#include <vector>
using namespace std;

void ask(vector<int> &a, const int idx) {
  if (a[idx] != -1) return;
  cout << "? " << idx + 1 << endl;
  cin >> a[idx];
}

void say(const int pos) {
  cout << "! " << pos + 1 << endl;
}

void bin_search(const int n) {
  vector<int> a(n, -1);
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    ask(a, mid);
    ask(a, mid + 1);
    if (a[mid] < a[mid + 1]) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  say(lo);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  bin_search(n);
}