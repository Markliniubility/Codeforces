#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=100;
const ll mod=998244353;
const ll inf=2000000000000000001;

int dp[N][N];
int mat[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> mat[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= k; i++) {
            dp[k][i] = mat[k][i] + max(dp[k - 1][i], dp[k - 1][i - 1]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[n][i]);
    }

    cout << res << endl;

    return 0;
}