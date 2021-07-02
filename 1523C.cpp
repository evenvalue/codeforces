#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define int64 int64_t
#define debug(x) cerr << #x << ": " << x << '\n'

const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void print_vec(const vector<int> &v) {
  const int n = v.size();
  for (int i = 0; i < n; i++) {
    cout << v[i] << (i == (n - 1) ? '\n' : '.');
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> stack;
  stack.reserve(n);
  while (n--) {
    int x;
    cin >> x;
    if (x == 1) stack.push_back(1);
    else {
      while (stack.back() != x - 1) {
        stack.pop_back();
      }
      stack.pop_back();
      stack.push_back(x);
    }
    print_vec(stack);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}