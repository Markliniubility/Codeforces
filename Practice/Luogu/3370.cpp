#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll N=3000;
const ll mod=998244353;
const ll inf=2000000000000000001;

set<ll> hashset;
ll base = 31;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        ll hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = hash * base + (int)(s[i] - 'a');
        }
        hashset.insert(hash);
    }

    cout << hashset.size() << endl;
    return 0;
}