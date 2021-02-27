#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, b;
  cin >> n >> b;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  a.push_back(1e9 + 10);
  vector<int> cut;
  for (int i = 0, evod = 0; i < n; i++) {
    evod += a[i] % 2 == 0 ? 1 : -1;
    if (evod == 0) {
      cut.push_back(abs(a[i] - a[i + 1]));
    }
  }
  sort(cut.begin(), cut.end());
  int spent = 0;
  for (int i = 0; i < cut.size(); i++) {
    if (spent + cut[i] > b) {
      cout << i << "\n";
      return 0;
    }
    spent += cut[i];
  }
  cout << (int)cut.size() - 1 << "\n";
}