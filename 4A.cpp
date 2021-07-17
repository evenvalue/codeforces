#include <iostream>
using namespace std;

int main() {
  int w;
  cin >> w;
  cout << (w & 1 or (w == 2) ? "NO" : "YES") << '\n';
}