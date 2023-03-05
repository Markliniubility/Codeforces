#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int scores[100010];
int n, T;

bool is_valid(int k) {
  int a_minus = 0, b_minus = 0, c_minus = 0;
  for (int i = 1; i <= n; i++) {
    double s = scores[i] * 1.0 / k;
    if (s >= 0.9) {
      a_minus++;
    }
    if (s >= 0.8) {
      b_minus++;
    }
    if (s >= 0.7) {
      c_minus++;
    }
  }

  return (a_minus * 4 >= n) && (b_minus * 2 >= n) && (c_minus * 4 / 3 >= n); 
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> T;
  int zeros = 0;
  for (int i = 1; i <= n; i++) {
    cin >> scores[i];
    if (!scores[i]) {
      zeros++;
    }
  }
  if (zeros * 4 > n) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = T; i > 0; i--) {
    if (is_valid(i)) {
        cout << i << endl;
        return 0;
    } 
  }
  cout << -1 << endl;
  return 0;
}