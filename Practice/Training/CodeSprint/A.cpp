#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define endl '\n'
#define ll long long

int N, M;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  int res = (M % N == 0) ? 0 : 1;
  cout << res << endl;
  return 0;
}