#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void solve() {
  int per;
  cin >> per;

  int g = gcd(per, 100);

  cout << 100 / g << "\n";
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