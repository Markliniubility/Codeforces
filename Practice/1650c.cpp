#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    int segments, points;
    cin >> segments >> points;
    segments *= 2;
    vector< vector<int> > mat; // weight, x-index, original index
    int sum = 0;
    for (int i = 0; i < points; i++) {
        int x, w;
        cin >> x >> w;
        vector<int> v;
        v.push_back(w);
        v.push_back(x);
        v.push_back(i);
        mat.push_back(v);
    }
    std::sort(mat.begin(), mat.end());

    for (int i = segments - 1; i < points - 1; i++) {
        mat.pop_back();
    }

    for (int i = 0; i < segments; i++) {
        sum += mat[i][0];
    }

    cout << sum << "\n";

    std::sort(mat.begin(), mat.end(),
    [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    for (int i = 0; i < segments; i++) {
        if (i >= segments - i - 1) {
            break;
        }
        cout << mat[i][2] + 1 << " " << mat[segments - i - 1][2] + 1 << "\n";
    }
  }
  return 0;
}