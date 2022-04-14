#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll N=3000;
const ll mod=998244353;
const ll inf=2000000000000000001;
int mat[N][N];
int diff[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x2 + 1][y1]--;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + diff[i][j];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}