#include <iostream>
#include <vector>
using namespace std;

bool possible(const vector<int> &x, const int len) {
  bool ret = true;
  for (int i = len; i < x.size(); i++) {
    ret &= (x[i] == x[i - len]);
  }
  return ret;
}

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
  vector<int> x(n);
  x[0] = a[0];
  for (int i = 1; i < n; i++) {
    x[i] = a[i] - a[i - 1];
  }
  vector<int> ans;
  ans.reserve(n);
  for (int len = 1; len <= n; len++) {
    if (not possible(x, len)) continue;
    ans.push_back(len);
  }
  cout << ans.size() << '\n';
  for (int &len : ans) {
    cout << len << " ";
  }
  cout << "\n";
}