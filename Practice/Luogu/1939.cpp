#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

ll mod = 1000000000 + 7;
struct Matrix {
  ll a[4][4];

  Matrix() {
    memset(a, 0, sizeof a);
  }

  Matrix operator*(const Matrix& m) const {
    Matrix res;
    
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        for (int k = 1; k <= 3; k++) {
          res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
        }
      }
    }

    return res;
  }
} ans, base_matrix;

void init() {
  base_matrix.a[1][1] = base_matrix.a[3][1] = base_matrix.a[1][2] = base_matrix.a[2][3] = 1;
  ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 1;
}

Matrix pow(Matrix base, ll p) {
  if (p <= 1) {
    return base;
  }
  Matrix half = pow(base, p / 2);
  if (p % 2) {
    return half * half * base;
  } else {
    return half * half;
  }
}

void solve() {
  ll n;
  cin >> n;
  if (n <= 3) {
    cout << 1 << endl;
    return;
  }
  Matrix eq = pow(base_matrix, n - 3);

  cout << (ans * eq).a[1][1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  init();
  while (tt--) {
    solve();
  }
  return 0;
}