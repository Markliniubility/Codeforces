#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

int N, P, X, Y;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> P >> X >> Y;
  N--;
  int res = P / N * (N * X + Y) + (P % N) * X;
  cout << res << endl;
  return 0;
}