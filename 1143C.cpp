#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> good(n);
    vector<bool> respect(n, true);
    for (int i = 0; i < n; i++) {
        int p, r;
        cin >> p >> r;
        if (p == -1) continue;
        good[p - 1] += 1 - r;
        respect[i] = (r == 0);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (not respect[i] and good[i] == 0) {
            ans.push_back(i + 1);
        }
    }
    if (ans.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}