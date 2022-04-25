#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

ll mat[25][25];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j <= N; j++) {
      cin >> mat[i][j];
    }
  }

  map<ll,ll> dp[N + 1];
  dp[0][0] = 1;

  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j <= N; j++) {
      ll prob = mat[i][j];
      for (const auto& [used, value] : dp[i - 1]) {
        ll check = (1 << j) & used;
        if ((1 << j) & used) {
          continue;
        }
        if (dp[i].find((1 << j) | used) == dp[i].end()) {
          dp[i][(1 << j) | used] = 0;
        }
        dp[i][(1 << j) | used] = max(value * prob, dp[i][(1 << j) | used]);
        // cout << "Updated: " << ((1 << j) | used) << " " << dp[i][(1 << j) | used] << endl;
      }
    }
  }
  ll helper = 0;
  for (ll i = 1; i <= N; i++) {
    helper |= (1 << i);
  }

  string res = to_string(dp[N][helper]);
  int pos = res.size() - 2 * (N - 1);
  if (pos < 0) {
    cout << "0.";
    while (pos < 0) {
      cout << "0";
    }
    cout << res << endl;
  } else {
    res.insert(pos, ".");
    cout << res << endl;
  }
  return 0;
}

