#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int drunk = 0;
  int64 health = 0;
  multiset<int> taken;
  int start = distance(a.begin(), find_if(a.begin(), a.end(), [](const int x) {
                         return x >= 0;
                       }));
  for (int i = start; i < n; i++) {
    if (health + a[i] < 0) {
      if (a[i] < *taken.begin()) continue;
      health -= *taken.begin();
      taken.erase(taken.begin());
      taken.insert(a[i]);
      health += a[i];
    } else {
      health += a[i];
      taken.insert(a[i]);
      drunk++;
    }
  }
  cout << drunk << '\n';
}