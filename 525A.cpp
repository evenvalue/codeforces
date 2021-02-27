#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> keys(26, 0);
    int ans = 0;
    for (char c : s) {
        if ('a' <= c and c <= 'z') {
            keys[c - 'a']++;
        } else if (keys[c - 'A'] > 0) {
            keys[c - 'A']--;
        } else {
            ans++;
        }
    }
    cout << ans << "\n";
}
