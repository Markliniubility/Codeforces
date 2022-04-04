#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, na, nb;
  cin >> n >> na >> nb;
  vector<int> a(na);
  vector<int> b(nb);
  for (int i = 0; i < na; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  }

  int res1 = 0, res2 = 0;
  for (int i = 0; i < n; i++) {
    int act1 = a[i % na];
    int act2 = b[i % nb];
    if (act1 == 0) {
      if (act2 == 0) {
        continue;
      } else if (act2 == 1 || act2 == 4) {
        res2 += 1;
      } else {
        res1++;
      }
    } else if (act1 == 1) {
      if (act2 == 1) {
        continue;
      } else if (act2 == 2 || act2 == 4) {
        res2 += 1;
      } else {
        res1++;
      }
    } else if (act1 == 2) {
      if (act2 == 2) {
        continue;
      } else if (act2 == 3 || act2 == 0) {
        res2 += 1;
      } else {
        res1++;
      }
    } else if (act1 == 3) {
      if (act2 == 3) {
        continue;
      } else if (act2 == 0 || act2 == 1) {
        res2 += 1;
      } else {
        res1++;
      }
    } else {
      if (act2 == 4) {
        continue;
      } else if (act2 == 2 || act2 == 3) {
        res2 += 1;
      } else {
        res1++;
      }
    }
  }
  cout << res1 << " " << res2 << endl;
  return 0;
}