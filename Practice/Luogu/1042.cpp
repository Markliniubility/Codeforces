#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

vector<vector<int>> v1;
vector<vector<int>> v2;

void helper(int &a, int &b, int limit) {
  if (max(a, b) >= limit && abs(a - b) >= 2) {
    vector<int> v{a,b};
    if (limit == 11) {
      v1.push_back(v);
    } else {
      v2.push_back(v);
    }
    a = b = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a11 = 0, b11 = 0, a21 = 0, b21 = 0;
  while (true) {
    char c;
    cin >> c;
    if (c == 'E') break;
    if (c == 'W') {
      a11++;
      a21++;
    } else if (c == 'L') {
      b11++;
      b21++;
    }
  
    helper(a11, b11, 11);
    helper(a21, b21, 21);
  }
  for (vector<int> v: v1) {
    cout << v[0] << ":" << v[1] << endl;
  }
  cout << a11 << ":" << b11 << endl << endl;

  for (vector<int> v: v2) {
    cout << v[0] << ":" << v[1] << endl;
  }
  cout << a21 << ":" << b21 << endl;

  
}