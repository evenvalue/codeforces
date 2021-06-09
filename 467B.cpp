#include <iostream>
#include <vector>
using namespace std;

int bit_count(int x) {
  int cnt = 0;
  while (x) {
    cnt += x & 1;
    x >>= 1;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> players(m + 1);
  for (int &player : players) {
    cin >> player;
  }
  int friends = 0;
  for (int player : players) {
    friends += bit_count(player ^ players[m]) <= k;
  }
  cout << friends - 1 << '\n';
}