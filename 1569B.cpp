#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(const int TestCase) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> won(n);
  vector<string> ans(n, string(n, 'X'));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == '1' or s[j] == '1') {
        ans[i][j] = '=';
      } else if (won[i] == 0) {
        ans[i][j] = '+';
        won[i]++;
      } else {
        ans[i][j] = '-';
        won[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (ans[j][i] == '=') {
        ans[i][j] = '=';
      } else {
        ans[i][j] = (ans[j][i] == '+' ? '-' : '+');
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (const int cnt = count(ans[i].begin(), ans[i].end(), '-'); cnt) {
        cout << "NO" << '\n';
        return;
      }
    } else {
      if (const int cnt = count(ans[i].begin(), ans[i].end(), '+'); cnt == 0) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES\n";
  for (const string &row : ans) {
    cout << row << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto start = chrono::steady_clock::now();

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = chrono::steady_clock::now();
  double diff = chrono::duration_cast<chrono::seconds>(end - start).count();
  cerr << diff << '\n';
}