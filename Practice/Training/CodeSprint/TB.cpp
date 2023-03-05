#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

ll scores[800010];
ll n, T;

bool is_valid(ll k) {
  ll a_minus = 0, b_minus = 0, c_minus = 0;
  for (ll i = 1; i <= n; i++) {
    double s = scores[i] * 1.0 / k;
    if (s >= 0.9) {
      a_minus++;
    }
    if (s >= 0.8) {
      b_minus++;
    }
    if (s >= 0.7) {
      c_minus++;
    }
  }

  return (a_minus * 4 >= n) && (b_minus * 2 >= n) && (c_minus * 4 / 3 >= n); 
}

ll binary_s() {
  ll l = 1, r = T * 2;
  while (l < r - 1) {
    ll mid = l + (r - l) / 2;
    // cout << mid << endl;
    // cout << "Right: " << r << endl;
    // cout << "Left: " << l << endl;
    // cout << is_valid(mid) << endl;
    if (is_valid(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  if (is_valid(r)) {
    return r;
  } else if (is_valid(l)) {
    return l;
  } else {
    return -1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> T;
  ll zeros = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> scores[i];
    if (!scores[i]) {
      zeros++;
    }
  }
  if (zeros * 4 > n) {
    cout << -1 << endl;
  } else {
    cout << binary_s() << endl;
  }
  
  return 0;
}