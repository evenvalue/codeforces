#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> p, m, s;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t == 1) p.push_back(i);
    if (t == 2) m.push_back(i);
    if (t == 3) s.push_back(i);
  }
  const int w = min({p.size(), m.size(), s.size()});
  cout << w << '\n';
  for (int i = 0; i < w; i++) {
    cout << p[i] << ' ' << m[i] << ' ' << s[i] << '\n';
  }
}