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
    int l, r, a;
    cin >> l >> r >> a;
    int cand1 = r / a + r % a;
    int cand2 = r - r % a - 1 < l ? 0 : r / a - 1 + a - 1;
    cout << max(cand1, cand2) << "\n";
  }
  return 0;
}
