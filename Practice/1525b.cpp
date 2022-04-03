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

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  bool inOrder = true;
  for (int i = 0; i < n; i++) {
    if (v[i] != i + 1) {
      inOrder = false;
    }
  }

  if (inOrder) {
    cout << "0" << endl;
  } else if (v[0] == 1 || v[n - 1] == n) {
    cout << "1" << endl;
  } else if (v[0] == n && v[n - 1] == 1) {
    cout << "3" << endl;
  } else {
    cout << "2" << endl;
  }

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