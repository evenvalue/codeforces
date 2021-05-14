#include <iostream>
#include <vector>
using namespace std;

int query(const int x) {
  cout << x << endl;
  string s;
  cin >> s;
  return (s == "yes");
}

int solve() {
  const vector<int> squares = {4, 9, 25, 49};
  const vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int cnt = 0;
  for (const int x : squares) {
    cnt += query(x);
  }
  for (const int x : prime) {
    cnt += query(x);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout << (solve() > 1 ? "composite" : "prime") << endl;
}