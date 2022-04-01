#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    int len;
    cin >> len;
    bool found = false;
    unordered_set<int> set;

    while (len--) {
        int temp;
        cin >> temp;
        if (set.find(temp) != set.end()) {
            found = true;
            // break; WHAT THE ACTUAL FUCK????
        } else {
            set.insert(temp);
        }
    }

    cout << (found ? "YES" : "NO") << "\n";
  }
  return 0;
}
