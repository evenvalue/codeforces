#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  string s;
  cin >> s;
  vector<pair<int, int>> to_sort = {{0, 0}};
  for (int i = 1; i < n; i++) {
    if (s[i] == '1' and s[i - 1] == '0') {
      to_sort.emplace_back(i, i);
    } else if (s[i] == '1' or s[i - 1] == '1') {
      to_sort.back().second++;
    }
  }
  for (pair<int, int> &x : to_sort) {
    sort(a.begin() + x.first, a.begin() + x.second + 1);
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}