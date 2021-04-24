#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int64 kInf = 1e15;

  struct strings {
    string s;
    string rs;
  };

  int n;
  cin >> n;
  vector<int> c(n);
  for (int &x : c) {
    cin >> x;
  }
  vector<strings> str(n);
  for (strings &st : str) {
    string s;
    cin >> s;
    st.s = s;
    reverse(s.begin(), s.end());
    st.rs = s;
  }
  vector<int64> same(n, kInf);
  vector<int64> reversed(n, kInf);
  same[0] = 0;
  reversed[0] = c[0];
  for (int i = 1; i < n; i++) {
    same[i] = (str[i - 1].s <= str[i].s ? min(same[i], same[i - 1]) : same[i]);
    same[i] = (str[i - 1].rs <= str[i].s ? min(same[i], reversed[i - 1]) : same[i]);
    reversed[i] = (str[i - 1].s <= str[i].rs ? min(reversed[i], same[i - 1] + c[i]) : reversed[i]);
    reversed[i] = (str[i - 1].rs <= str[i].rs ? min(reversed[i], reversed[i - 1] + c[i]) : reversed[i]);
  }
  const int64 ans = min(same[n - 1], reversed[n - 1]);
  cout << (ans == kInf ? -1 : ans);
}