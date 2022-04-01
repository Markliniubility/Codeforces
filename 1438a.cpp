#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int len;
  cin >> len;
  for (int i = 0; i < len; i++) {
    int k;
    cin >> k;
    while (k-- > 0) {
        cout << 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
