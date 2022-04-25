#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n  m;
  vector< vector<int> > dist(m + 100);
  vector<int> deg(m + 100);

  for (int i = 1; i <= m; i++) {
    int s1, s2, d;
    cin >> s1 >> s2 >> d;
    deg[s1]++;
    deg[s2]++;
    
  }
  return 0;
}
