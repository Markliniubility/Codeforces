#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

// hashmap = {
//     1: 1, # for any number
//     2: 4, # 1 + 4k
//     3: 4, # 1 + 4k
//     4: 2, # 1 + 2k
//     5: 1, # for all number
//     6: 1, # for all number
//     7: 4, # 1 + 4k
//     8: 4, # 1 + 4k
//     9: 2, # 1 + 2k
// }

ll scores[100010];
ll n;
ll mod = 1000000;

inline bool ends_with(std::string const & value, std::string const & ending) {
  if (ending.size() > value.size()) return false;
  return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

ll bin_pow(long long a, long long b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    a %= 10000;
    b >>= 1;
  }
  return res;
}

int solve(int mul) {
  int res = -1; 
  for (int i = 1 + mul; i < 1000000; i += mul) {
    bool valid = true;
    for (int k = 1; k <= n; k++) {
      if (!valid) break;
      ll s = scores[k];
      string str = to_string(s);
      ll p = bin_pow(s, i);
      string str_p = to_string(p);
      if (!ends_with(str_p, str)) {
        valid = false;
        break;
      }
    }

    if (valid) {
      res = i;
      break;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  
  bool fours = false, twos = false, ones = false;
  bool seenNonZero = false;

  for (int i = 1; i <= n; i++) {
    int xx;
    cin >> xx;
    scores[i] = xx;
    int x = xx % 10;
    if (x == 0) {
      cout << -1 << endl;
      return 0;
    }
    if (x == 2 || x == 3 || x == 7 || x == 8) {
      fours = true;
    } else if (x == 4 || x == 9) {
      twos = true;
    } else {
      ones = true;
    }
  }

  if (fours) {
    cout << solve(4) << endl;
  } else if (twos) {
    cout << solve(2) << endl;
  } else {
    cout << solve(1) << endl;
  }
  
  return 0;
}