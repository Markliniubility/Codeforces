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
    if (!(k % 2)) {
        cout << k << " is even" << endl;
    } else {
        cout << k << " is odd" << endl;
    }
    cout << "\n";
  }
  return 0;
}
