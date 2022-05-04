#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

ll mod;

struct Matrix {
    ll a[3][3];

    Matrix () {
        memset(a, 0, sizeof a);
    }

    Matrix operator* (const Matrix& m) const {
        Matrix res;
        for (ll i = 1; i <= 2; i++) {
            for (ll j = 1; j <= 2; j++) {
                for (ll k = 1; k <= 2; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
                }
            }
        }
        return res;
    }
} base, ans;

Matrix pow(Matrix b, ll p) {
    if (p <= 1) {
        return b;
    }
    Matrix half = pow(b, p / 2);
    if (p % 2) {
        return half * half * b;
    } else {
        return half * half;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cin >> mod;

    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ans.a[1][1] = ans.a[1][2] = 1;

    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }

    Matrix eq = pow(base, n - 2);

    cout << (ans * eq).a[1][1] << endl;
    return 0;
}