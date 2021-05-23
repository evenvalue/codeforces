#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kInf = 1e9 + 10;

  int n, k, m;
  cin >> n >> k >> m;
  map<string, int> idx;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    idx[s] = i;
  }
  vector<int> cost(n);
  for (int &x : cost) {
    cin >> x;
  }
  vector<int> grp(n);
  vector<int> best(k, kInf);
  for (int i = 0; i < k; i++) {
    int sz;
    cin >> sz;
    for (int j = 0; j < sz; j++) {
      int x;
      cin >> x;
      grp[x - 1] = i;
      best[i] = min(best[i], cost[x - 1]);
    }
  }
  int64 ans = 0;
  while (m--) {
    string s;
    cin >> s;
    ans += best[grp[idx[s]]];
  }
  cout << ans << '\n';
}