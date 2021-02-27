#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  string s3 = {s1.front(), s1.back(), s2.front(), s2.back()};
  cout << (s3 == "><^v" or s3 == "<>v^" ? "YES" : "NO") << "\n";
}