#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

int powi (int base, unsigned int exp)
{
    int res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}

void solve() {
  int w;
  cin >> w;
  vector<int> v;
  while (w > 0) {
    v.push_back(w % 3);
    w /= 3;
  }
  vector<int> left, right;
  // reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    int num = v.at(i);
    if (num == 1) {
      right.push_back(powi(3, i));
    } else if (num == 2) {
      // minus is required
      left.push_back(powi(3, i++));
      while (i < v.size() && v.at(i) != 0) {
        int diff = 2 - v.at(i);
        if (diff > 0) {
          left.push_back(powi(3, i));
        }
        i++;
      }
      right.push_back(powi(3, i));
    }
  }
  reverse(left.begin(), left.end());
  reverse(right.begin(), right.end());
  cout << "left pan: ";
  for (int i: left) {
    cout << i << " ";
  }
  cout << endl;

  cout << "right pan: ";
  for (int i: right) {
    cout << i << " ";
  }
  cout << endl << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}