#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

ll p, q, a1, a2, n, mod;

struct Matrix {
  ll a[3][3];

  Matrix() {
    memset(a, 0, sizeof a);
  }

  Matrix operator*(const Matrix& m) const {
    Matrix res;
    
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= 2; j++) {
        for (int k = 1; k <= 2; k++) {
          res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
        }
      }
    }

    return res;
  }
} ans, base_matrix;

void init() {
  base_matrix.a[1][1] = p;
  base_matrix.a[1][2] = 1;
  base_matrix.a[2][1] = q;
  ans.a[1][1] = a2;
  ans.a[1][2] = a1;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> p >> q >> a1 >> a2 >> n >> mod;
  if (n == 2) {
    cout << a2 << endl; return 0;
  } else if (n == 1) {
    cout << a1 << endl; return 0;
  }
  init();
  Matrix eq = pow(base_matrix, n - 2);

  cout << (ans * eq).a[1][1] << endl;
  return 0;
}