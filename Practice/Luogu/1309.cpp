#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

bool cmp(vector<int> v1, vector<int> v2)
{
  if (v1.at(0) < v2.at(0))
    return true;
  else 
    return v1.at(1) > v2.at(1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, R, Q;
  cin >> n >> R >> Q;
  vector<vector<int>> v(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    vector<int> pair(3);
    cin >> pair[0]; // score, ability, and number
    pair[1] = (i + 1);
    v[i] = pair;
  }

  for (int i = 0; i < 2 * n; i++) {
    cin >> v.at(i)[2];
  }
  
  for (int i = 0; i < R; i++) {
    sort(v.begin(), v.end(), cmp);
    for (int k = 0; k < 2 * n; k += 2) {
      if (v[k][2] > v[k + 1][2]) {
        v[k][0]++;
      } else {
        v[k + 1][0]++;
      }
    }
  }
  sort(v.begin(), v.end(), cmp);
  cout << v[2 * n - Q][1] << endl;
  return 0;
}