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

  int n;
  cin >> n;
  bool printed = false;
  for (int i = 0; i < n; i++) {
    int co;
    cin >> co;
    if (co == 0) {
      continue;
    }
    if (i != 0 && co > 0 && printed) {
      cout << "+";
    } else if (co < 0) {
      cout << "-";
    }
    co = abs(co);
    if (co != 1) {
      cout << co;
    }
    if (n - i > 1)
      cout << "x^" << (n - i);
    else
      cout << "x";

    printed = true;
  }
  int co;
  cin >> co;
  if (co > 0 && printed) {
    cout << "+" << co;
  } else if (co != 0) {
    cout << co;
  }
  cout << endl;
  return 0;
}