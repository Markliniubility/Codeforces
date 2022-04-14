#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll N=3000;
const ll mod=998244353;
const ll inf=2000000000000000001;
int mat[N][N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mat[i][j]) {
                continue;
            }
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            res = max(res, dp[i][j]);
        }
    }

    cout << res << endl;
    return 0;
}