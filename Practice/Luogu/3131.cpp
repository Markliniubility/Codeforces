#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    int map[7];
    cin >> n;
    for (int i = 0; i < 7; i++) {
        map[i] = -100;
    }
    ll prefix = 0;
    map[0] = 0;
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        ll cur;
        cin >> cur;
        cur %= 7;
        prefix += cur;
        prefix %= 7;

        // prefix - x = 7
        if (map[prefix] != -100) {
            res = max(res, i - map[prefix]);
        } else {
            map[prefix] = i;
        }
    }
    
    cout << res << endl;
    return 0;
}