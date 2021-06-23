#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n), h(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  x.push_back(2e9 + 10);
  int fell = 1;
  for (int i = 1; i < n; i++) {
    if (x[i] - h[i] > x[i - 1]) {
      fell++;
    } else if (x[i] + h[i] < x[i + 1]) {
      x[i] = x[i] + h[i];
      fell++;
    }
  }
  cout << fell << '\n';
}