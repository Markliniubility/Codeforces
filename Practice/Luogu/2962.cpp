#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

int a[40][40];
int x[40];
ll ans = 100000000;
int n, m;

void swapRows(int r1, int r2) {
  for (int i = 1; i <= n + 1; i++) {
    swap(a[r1][i], a[r2][i]);
  }
}

void dfs(int xx, ll res) {
  if (res > ans) {
    return;
  }
  if (xx <= 0) {
    ans = min(res, ans);
    return;
  }
  // if the coeffient is on it
  // it must be on the vector
  if (a[xx][xx]) {
    x[xx] = a[xx][n + 1];
    for (int j = n; j > xx; j--) {
      x[xx] ^= a[xx][j] & x[j];
    }
    if (x[xx]) {
      dfs(xx - 1, res + 1);
    } else {
      dfs(xx - 1, res);
    }
  } else {
    x[xx] = 0;
    dfs(xx - 1, res);
    x[xx] = 1;
    dfs(xx - 1, res + 1);
  }
}

void gauss() {
  // eliminationn k-th column 
  for (int k = 1; k <= n; k++) {
    // find if there is a row with coeff 1 below
    for (int i = k + 1; i <= n; i++) {
      if (a[i][k]) {
        swap(a[k], a[i]);
        break;
      }
    }

    // if there is a leading coeff with 1,
    // xor the entire row to eliminate
    for (int i = k + 1; i <= n; i++) {
      if (a[i][k]) {
        for (int j = 1; j <= n + 1; j++) {
          a[i][j] ^= a[k][j];
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    a[i][i] = 1;
    a[i][n + 1] = 1;
  }
  
  gauss();
  dfs(n, 0l);
  cout << ans << endl;
  return 0;
}
