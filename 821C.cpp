#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0, small = 1;
  vector<int> v;
  set<int> s;
  n += n;
  while (n--) {
    string type;
    cin >> type;
    if (type == "add") {
      int x;
      cin >> x;
      v.push_back(x);
      continue;
    }
    if (not v.empty() and v.back() != small) {
      ans++;
      for (int x: v) {
        s.insert(x);
      }
      v.clear();
    }
    if (v.empty()) {
      s.erase(small);
    } else {
      v.pop_back();
    }
    small++;
  }
  cout << ans << "\n";
}