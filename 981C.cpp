#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<vector<int>> &g, const int x, const int p) {
    for (int y : g[x]) {
        if (y == p) continue;
        return dfs(g, y, x);
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0, hub = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            res++;
            hub = i;
        }
    }
    if (res > 1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << g[hub].size() << "\n";
    for (int nbr : g[hub]) {
        cout << hub + 1 << " " << dfs(g, nbr, hub) + 1 << "\n";
    }
}