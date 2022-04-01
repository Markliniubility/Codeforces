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
    string s;
    char c;
    cin >> s >> c;
    int len = s.length();
    bool found = false;
    for (int i = 0; i < len; i += 2) {
        if (s[i] == c) {
            found = true;
            break;
        }
    }
    cout << (found ? "YES" : "NO") << "\n";
  }
  return 0;
}
