#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
  int x, y;
};

int main() {
  int n;
  cin >> n;
  vector<edge> edges(n - 1);
  vector<int> d(n, 0);
  for (edge &e : edges) {
    cin >> e.x >> e.y;
    e.x--;
    e.y--;
    d[e.x]++;
    d[e.y]++;
  }
  int hub = distance(d.begin(), max_element(d.begin(), d.end()));
  int big = n - 2, small = 0;
  for (const edge &e : edges) {
    if (e.x == hub or e.y == hub) {
      cout << small << "\n";
      small++;
    } else {
      cout << big << "\n";
      big--;
    }
  }
}