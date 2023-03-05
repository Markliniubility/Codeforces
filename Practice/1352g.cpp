#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;


void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
        return;
    }
    int init = 1;
    if (n % 2 == 0) {
        init = 2;
    }
    for (int i = init; i <= n; i += 2) {
        cout << i << ' ';
    }
    cout << n - 3 << ' ' << n - 1 << ' ';
    for (int i = n - 5; i >= 1; i -= 2) {
        cout << i << ' ';
    }
    cout << endl;
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