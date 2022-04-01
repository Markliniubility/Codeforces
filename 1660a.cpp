#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > 0) {
        cout << (a + b * 2 + 1) << "\n";
    } else {
        cout << (1)  << "\n";
    }
    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}