#include <iostream>
#include <vector>
using namespace std;

int ask(const int x, const int y) {
  cout << "? " << x + 1 << " " << y + 1 << endl;
  int mod;
  cin >> mod;
  return mod;
}

void say(const vector<int> &a) {
  cout << "!";
  for (const int x : a) {
    cout << " " << x;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n, -1);
  int hi = 0;
  for (int i = 1; i < n; i++) {
    const int mod1 = ask(hi, i);
    const int mod2 = ask(i, hi);
    if (mod1 > mod2) {
      a[hi] = mod1;
      hi = i;
    } else {
      a[i] = mod2;
    }
  }
  a[hi] = n;
  say(a);
}