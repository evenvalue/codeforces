#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h;
  cin >> h;
  vector<int> a(h + 1);
  int n = 0;
  for (int &x : a) {
    cin >> x;
    n += x;
  }
  bool perfect = true;
  for (int i = 1; i <= h; i++) {
    if (a[i] != 1 and a[i - 1] != 1) {
      perfect = false;
      break;
    }
  }
  if (perfect) {
    cout << "perfect" << "\n";
    return 0;
  }
  cout << "ambiguous" << "\n";
  vector<vector<int>> depth(h + 1);
  for (int level = 0, node = 0; level <= h; level++) {
    for (int rank = 0; rank < a[level]; rank++, node++) {
      depth[level].push_back(node);
    }
  }
  vector<int> p1(n, -1);
  vector<int> p2(n, -1);
  for (int level = 1; level <= h; level++) {
    for (int node : depth[level]) {
      p1[node] = depth[level - 1][0];
      p2[node] = depth[level - 1][0];
    }
    p2[depth[level][0]] = depth[level][0] - 1;
  }
  for (int parent : p1) {
    cout << parent + 1 << " ";
  }
  cout << "\n";
  for (int parent : p2) {
    cout << parent + 1 << " ";
  }
}