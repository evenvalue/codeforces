#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (const char c : s) {
      cnt += (c == '(');
      cnt = max(0, cnt - (c == ')'));
    }
    cout << cnt << '\n';
  }
}