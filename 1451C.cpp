#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<int> freq(26, 0);
    for (char c : a) {
      freq[c - 'a']++;
    }
    for (char c : b) {
      freq[c - 'a']--;
    }
    int cnt = 0;
    bool ans = true;
    for (int x : freq) {
      cnt += x;
      if (cnt < 0 or cnt % k != 0) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << "\n";
  }
}