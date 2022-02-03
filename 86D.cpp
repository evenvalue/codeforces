#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using int64 = int64_t;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

int readInt() {
  int x;
  cin >> x;
  return x;
}
int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
char readChar() {
  char c;
  cin >> c;
  return c;
}
string readString() {
  string s;
  cin >> s;
  return s;
}
double readDouble() {
  return stod(readString());
}
ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

class Mo_s {
  struct query {
    int idx;
    int l, r;
  };

  static const int kBlock = 500;

  static int block(const int i) {
    return i / kBlock;
  }

  vector<query> queries;
  const vector<int> a;

public:
  Mo_s(const vector<int> &a) : a(a) {}

  void add(const int l, const int r) {
    queries.push_back({(int)queries.size(), l, r});
  }

  vector<int64> solve() {
    sort(queries.begin(), queries.end(), [](const query &q1, const query &q2) {
      if (block(q1.l) != block(q2.l)) {
        return q1.l < q2.l;
      }
      return (block(q1.l) & 1 ? q1.r > q2.r : q1.r < q2.r);
    });

    vector<int> freq(1e6 + 5);

    int64 ans = 0;
    
    auto add = [&](const int i) {
      ans -= (freq[a[i]] * 1LL * freq[a[i]] * 1LL * a[i]);
      freq[a[i]]++;
      ans += (freq[a[i]] * 1LL * freq[a[i]] * 1LL * a[i]);
    };

    auto del = [&](const int i) {
      ans -= (freq[a[i]] * 1LL * freq[a[i]] * 1LL * a[i]);
      freq[a[i]]--;
      ans += (freq[a[i]] * 1LL * freq[a[i]] * 1LL * a[i]);
    };

    vector<int64> answer(queries.size());

    for (int l = 0, r = -1, i = 0; i < queries.size(); i++) {
      while (l < queries[i].l) del(l++);
      while (l > queries[i].l) add(--l);
      while (r < queries[i].r) add(++r);
      while (r > queries[i].r) del(r--);
      answer[queries[i].idx] = ans;
    }

    return answer;
  }
};

void solution() {
  const int n = readInt(), t = readInt();
  const vector<int> &a = readVec<int>(n);
  Mo_s mo(a);
  for (int query = 0; query < t; query++) {
    const int l = readInt() - 1, r = readInt() - 1;
    mo.add(l, r);
  }
  const vector<int64> ans = mo.solve();
  for (const int64 &x : ans) {
    cout << x << '\n';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}