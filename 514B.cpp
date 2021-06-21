#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  struct coordinate {
    int x, y;
  };

  int n;
  coordinate l{};
  cin >> n >> l.x >> l.y;
  vector<coordinate> a(n);
  for (auto &c : a) {
    cin >> c.x >> c.y;
  }
  vector<bool> dead(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dead[i]) continue;
    for (int j = i; j < n; j++) {
      dead[j] = dead[j] or ((a[i].x - l.x) * (a[j].y - a[i].y) == (a[j].x - a[i].x) * (a[i].y - l.y));
    }
    ans++;
  }
  cout << ans << '\n';
}