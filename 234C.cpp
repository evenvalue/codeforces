#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int n;
  fin >> n;
  vector<int> t(1);
  vector<int> neg(1);
  for (int i = 0; i < n; i++) {
    int temp;
    fin >> temp;
    if (temp == 0) {
      t[0]++;
      continue;
    }
    t.push_back(temp);
    neg.push_back(neg.back() + (temp < 0));
  }
  if (t.size() == 1) {
    fout << t[0];
    return 0;
  }
  int ans = 1e9 + 10;
  for (int i = 1; i < t.size() - 1; i++) {
    ans = min(ans, (i - neg[i]) + neg.back() - neg[i]);
  }
  fout << ans + t[0] << "\n";
}