#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

void solve() {
  const int kInf = 1e15;

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> left(n, kInf);
  vector<int> right(n, kInf);
  int lt = kInf;
  for (int i = 0; i < n; i++, lt++) {
    if (s[i] == '1') lt = 0;
    left[i] = min(left[i], lt);
  }
  int rt = kInf;
  for (int i = n - 1; i >= 0; i--, rt++) {
    if (s[i] == '1') rt = 0;
    right[i] = min(right[i], rt);
  }
  for (int i = 0; i < n; i++) {
    if ((left[i] == right[i] or (left[i] > m and right[i] > m)) and left[i] != 0) {
      cout << 0;
    } else {
      cout << 1;
    }
  }
  cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}