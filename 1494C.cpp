#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int calc(const vector<int> &box, const vector<int> &pos) {
  const int n = box.size();
  const int m = pos.size();
  vector<int> suf(n + 1);
  for (int i = n - 1, p = m - 1; i >= 0; i--) {
    suf[i] = suf[i + 1];
    while (0 <= p and pos[p] > box[i]) {
      p--;
    }
    suf[i] += (0 <= p and pos[p] == box[i]);
  }
  int ans = suf[0];
  int train = 0;
  for (int left = 0, right = 0; left < m; left++) {
    while (train < n and box[train] <= pos[left] + train) {
      train++;
    }
    while (right < m and pos[right] - pos[left] < train) {
      right++;
    }
    ans = max(ans, right - left + suf[train]);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> box(n);
    vector<int> pos(m);
    for (int &b : box) {
      cin >> b;
    }
    for (int &p : pos) {
      cin >> p;
    }
    vector<int> boxl, boxr;
    vector<int> posl, posr;
    for (int x : box) {
      if (x < 0) {
        boxl.push_back(-x);
      } else {
        boxr.push_back(x);
      }
    }
    for (int x : pos) {
      if (x < 0) {
        posl.push_back(-x);
      } else {
        posr.push_back(x);
      }
    }
    reverse(boxl.begin(), boxl.end());
    reverse(posl.begin(), posl.end());
    cout << calc(boxl, posl) + calc(boxr, posr) << "\n";
  }
}