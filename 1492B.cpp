#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> deck(n);
    set<int> cards;
    for (int &card : deck) {
      cin >> card;
      cards.insert(card);
    }
    vector<int> ans;
    for (int i = n - 1, last = n ; i >= 0; i--) {
      if (deck[i] == *cards.rbegin()) {
        for (int j = i; j < last; j++) {
          ans.push_back(deck[j]);
        }
        last = i;
      }
      cards.erase(deck[i]);
    }
    for (int &card : ans) {
      cout << card << " ";
    }
    cout << "\n";
  }
}