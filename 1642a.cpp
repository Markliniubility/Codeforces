#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_set>
#include <math.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    vector<vector<int>> v;
    for (int i = 0; i < 3; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        vector<int> co;
        co.push_back(y1);
        co.push_back(x1);
        v.push_back(co);
    }
    
    sort(v.begin(), v.end());
    int res = 0;
    if (v[2][0] == v[1][0]) {
        res += (v[2][1] - v[1][1]);
    }

    cout << res << "\n";
  }
  return 0;
}