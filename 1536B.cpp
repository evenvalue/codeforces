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

void solve(const vector<string> &mex) {
  int n;
  string s;
  cin >> n >> s;
  for (const string &str : mex) {
    if (s.find(str) != string::npos) continue;
    cout << str;
    break;
  }
}

vector<string> build() {
  vector<string> mex;
  mex.reserve(18278);
  for (char c1 = 'a'; c1 <= 'z'; c1++) {
    for (char c2 = 'a'; c2 <= 'z'; c2++) {
      for (char c3 = 'a'; c3 <= 'z'; c3++) {
        mex.push_back({c1, c2, c3});
      }
      mex.push_back({c1, c2});
    }
    mex.push_back({c1});
  }
  sort(mex.begin(), mex.end(), [](const string &s1, const string &s2) {
    const int n = s1.size();
    const int m = s2.size();
    return (n != m ? n < m : s1 < s2);
  });
  return mex;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const vector<string> &mex = build();

  int t = 1;
  cin >> t;
  while (t--) {
    solve(mex);
    cout << '\n';
  }
}