#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    int l;
    cin >> l;
    vector<ll> a(l);
    set<ll> m;

    for (int i = 0; i < l; i++) {
        cin >> a[i];
        m.insert(a[i]);
    }

    int size = m.size();
    for (int k = 1; k <= size; k++) {
        cout << size << " ";
    }

    for (int k = size + 1; k <= l; k++) {
        cout << k << " ";
    }
    cout << "\n";
  }
  return 0;
}