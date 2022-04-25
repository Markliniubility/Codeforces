#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int scholarship(vector<int> v) {
  int res = 0;
  if (v[0] > 80 && v[4] >= 1) {
    res += 8000;
  }
  if (v[0] > 85 && v[1] > 80) {
    res += 4000;
  }
  if (v[0] > 90) {
    res += 2000;
  }
  if (v[3] && v[0] > 85) {
    res += 1000;
  }
  if (v[1] > 80 && v[2]) {
    res += 850;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> v(n);
  vector<vector<int>> stats(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    int f, a;
    cin >> f >> a;
    char g, w;
    cin >> g >> w;
    int p;
    cin >> p;
    bool gb = g == 'Y', wb = w == 'Y';
    vector<int> temp {f, a, gb, wb, p};
    int scho = scholarship(temp);
    temp.push_back(scho);
    stats[i] = temp;
  }
  sort()
  cout << v[2 * n - Q][1] << endl;
  return 0;
}