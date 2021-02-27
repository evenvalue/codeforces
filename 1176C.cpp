#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  {
    vector<int> ssq = {4, 8, 15, 16, 23, 42};
    for (int &x : a) {
      x = distance(ssq.begin(), lower_bound(ssq.begin(), ssq.end(), x));
    }
  }
  vector<int> sq(6);
  for (const int x : a) {
    if (x == 0) {
      sq[0]++;
    } else if (sq[x - 1] > 0) {
      sq[x - 1]--;
      sq[x]++;
    }
  }
  cout << n - (6 * sq[5]) << "\n";
}