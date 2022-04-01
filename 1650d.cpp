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
    int l;
    cin >> l;
    vector<int> v;

    for (int i = 1; i <= l; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    vector<int> path_rev;

    for (int i = l; i > 0; i--) {
        int index = 0;
        for (int k = 0; k < i; k++) {
            if (v.at(k) == i) {
                index = k;
                break;
            }
        }
        if (index == i - 1) {
            path_rev.push_back(0);
            continue;
        }
        path_rev.push_back(index + 1);
        rotate(v.begin(), v.begin() + index + 1, v.begin() + i);
    }

    reverse(path_rev.begin(),path_rev.end());

    for (int i: path_rev) {
        cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
