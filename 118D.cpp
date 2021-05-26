#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int kMod = 1e8;

  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  vector<vector<int>> foot(n1 + 1, vector<int>(n2 + 1));
  vector<vector<int>> horse(n1 + 1, vector<int>(n2 + 1));
  foot[0][0] = horse[0][0] = 1;
  for (int fm = 0; fm <= n1; fm++) {
    for (int hm = 0; hm <= n2; hm++) {
      for (int connect = 1; connect <= min(k1, fm); connect++) {
        foot[fm][hm] += horse[fm - connect][hm];
        foot[fm][hm] -= (foot[fm][hm] > kMod ? kMod : 0);
      }
      for (int connect = 1; connect <= min(k2, hm); connect++) {
        horse[fm][hm] += foot[fm][hm - connect];
        horse[fm][hm] -= (horse[fm][hm] > kMod ? kMod : 0);
      }
    }
  }
  cout << (foot[n1][n2] + horse[n1][n2]) % kMod << '\n';
}