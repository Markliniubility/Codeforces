#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=1000;
const ll mod=998244353;
const ll inf=2000000000000000001;

int dp[N][N];
int w[N], v[N];

// 71, 100
// 69, 1
// 1, 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int time, n;
    cin >> time >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i]; // time, value
    }

    // dp[i][j] the first i-th item with time j
    for (int i = 1; i <= n; i++) {
        int weight = w[i], value = v[i];
        for (int j = 0; j <= time; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - weight >= 0) {
                dp[i][j] = max(dp[i][j],dp[i - 1][j - weight] + value);
            }
        }
    }

    cout << dp[n][time] << endl;

    return 0;
}