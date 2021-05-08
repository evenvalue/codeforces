#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

const int kMod = 1e9 + 7;

struct matrix {
  int n;
  vector<vector<int>> a;

  explicit matrix(const int n) : n(n), a(n, vector<int>(n)) {}

  matrix operator*(const matrix &other) const {
    matrix ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          ret.a[i][k] = (ret.a[i][k] + ((int64) a[i][j] * other.a[j][k])) % kMod;
        }
      }
    }
    return ret;
  }
};

matrix binpow(const int n, matrix &m, int64 pow) {
  matrix product(n);
  for (int i = 0; i < n; i++) {
    product.a[i][i] = 1;
  }
  while (pow) {
    if (pow & 1) {
      product = product * m;
    }
    m = m * m;
    pow /= 2;
  }
  return product;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  matrix adj(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj.a[x - 1][y - 1] = 1;
  }
  const matrix mat = binpow(n, adj, k);
  int ans = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      ans += mat.a[x][y];
      ans -= (ans > kMod ? kMod : 0);
    }
  }
  cout << ans << "\n";
}
