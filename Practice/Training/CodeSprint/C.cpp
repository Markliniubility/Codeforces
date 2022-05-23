#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define endl '\n'
#define ll long long


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, P;
  cin >> N >> M >> P;
  int d[M + 10];

  for (int i = 1; i <= M; i++) {
    cin >> d[i];
  }

  // dp[h][b][p]
  int health = N;
  for (int i = 1; i <= M; i++) {
    if (health <= d[i] && P > 0) {
      int diff = d[i] - health;
      int p_used = diff / 20 + 1;
      health += min(p_used, P) * 20;
      health = min(N, health);
      P -= min(p_used, P);
    }
    health -= d[i];
    if (health <= 0) {
      break;
    }
  }
  string res = (health <= 0) ? "next time" : "champion";
  cout << res << endl;

  return 0;
}

