#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

int a[2005][2005];
int x[40];
int n, m;
int ans = 0;

bool gauss() {
  // eliminate col 1 to col n
  for (int k = 1; k <= n; k++) {
    bool empty = true;
    for (int i = k; i <= m; i++) {
      if (a[i][k]) {
        if (i != k) swap(a[i], a[k]);
        ans = max(ans, i);
        empty = false;
        break;
      }
    }

    if (empty) {
      return empty;
    }

    for (int i = k + 1; i <= m; i++) {
      if (a[i][k]) {
        for (int j = 1; j <= n + 1; j++) {
          a[i][j] ^= a[k][j];
        }
      }
    }
  }

  for (int k = n; k >= 1; k--) {
    for (int i = k - 1; i >= 1; i--) {
      if (a[i][k]) {
        for (int j = 1; j <= n + 1; j++) {
          a[i][j] ^= a[k][j];
        }
      }
    }
  }

  return false;
}

void printAns(int i) {
  if (i % 2) {
    cout << "?y7M#" << endl;
  } else {
    cout << "Earth" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  if (m < n) {
    cout << "Cannot Determine" << endl;
    return 0;
  }
  // the matrix a has demension m * n
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int k = 0; k < n; k++) {
      a[i][k + 1] = s[k] - '0';
    }
    cin >> a[i][n + 1];
  }
  
  bool empty = gauss();

  if (empty) {
    cout << "Cannot Determine" << endl;
    return 0;
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    printAns(a[i][n + 1]);
  }
  return 0;
}
