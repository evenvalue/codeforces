#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<pair<int, int>> q;
  vector<int> d(n), s(n);
  int edges = 0;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> s[i];
    q.insert({d[i], i});
    edges += d[i];
  }
  vector<int> p(n, -1);
  while (not q.empty()) {
    const int x = q.begin()->second;
    q.erase(q.begin());
    if (d[x] == 0) continue;
    p[x] = s[x];
    const int parent = p[x];
    q.erase(q.find({d[parent], parent}));
    d[parent]--;
    s[parent] ^= x;
    q.insert({d[parent], parent});
  }
  cout << edges / 2 << "\n";
  for (int i = 0; i < n; i++) {
    if (p[i] == -1) continue;
    cout << i <<  " " << p[i] << "\n";
  }
}