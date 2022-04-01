#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long

void solve() {
    int len;
    cin >> len;
    int lar = 0;
    int sec = 0;

    for (int i = 0; i < len; i++) {
        int t;
        cin >> t;
        if (t >= lar) {
            sec = lar;
            lar = t;
        } else if (t > sec) {
            sec = t;
        }
    }
    bool invalid = lar - sec >= 2;

    cout << (!invalid ? "YES": "NO") << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}