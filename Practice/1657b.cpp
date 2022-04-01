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

  long long cases;
  cin >> cases;
  while (cases--) {
    long long n, B, x, y;
    cin >> n >> B >> x >> y;
    long long sum = 0;
    long long a = 0;
    while (n--) {
        if (a + x <= B) {
            a += x;
        } else {
            a -= y;
        }
        sum += a;
    }
    cout << sum << "\n";
  }
  return 0;
}