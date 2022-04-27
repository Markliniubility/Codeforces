#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

double mat[25][25];
double dp[(1 << 20) + 5];

// 状态转移 dp[i] = max(dp[i xor 2^i] * value);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> mat[i][j];
      mat[i][j] *= 0.01;
    }
  }
  int total = (1 << N) - 1;
  dp[0] = 1;
  for (int i = 1; i <= total; i++) {
    int x=i,count=0;
		for(;x;x>>=1) if(x&1) count++;
    for (int k = 0; k < N; k++) {
      if (i & (1<<k)) {
        dp[i] = max(dp[i], dp[i^(1<<k)] * mat[count][k + 1]);
      }
    }
  }

  printf("%.6lf",dp[total]*100);
  return 0;
}
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   ll N;
//   cin >> N;
//   for (ll i = 1; i <= N; i++) {
//     for (ll j = 1; j <= N; j++) {
//       cin >> mat[i][j];
//     }
//   }

//   map<ll,ll> dp[N + 1];
//   dp[0][0] = 1;

//   for (ll i = 1; i <= N; i++) {
//     for (ll j = 1; j <= N; j++) {
//       ll prob = mat[i][j];
//       for (const auto& [used, value] : dp[i - 1]) {
//         ll check = (1 << j) & used;
//         if ((1 << j) & used) {
//           continue;
//         }
//         if (dp[i].find((1 << j) | used) == dp[i].end()) {
//           dp[i][(1 << j) | used] = 0;
//         }
//         dp[i][(1 << j) | used] = max(value * prob, dp[i][(1 << j) | used]);
//         // cout << "Updated: " << ((1 << j) | used) << " " << dp[i][(1 << j) | used] << endl;
//       }
//     }
//   }
//   ll helper = 0;
//   for (ll i = 1; i <= N; i++) {
//     helper |= (1 << i);
//   }

//   string res = to_string(dp[N][helper]);
//   int pos = res.size() - 2 * (N - 1);
//   if (pos < 0) {
//     cout << "0.";
//     while (pos < 0) {
//       cout << "0";
//     }
//     cout << res << endl;
//   } else {
//     res.insert(pos, ".");
//     cout << res << endl;
//   }
//   return 0;
// }

