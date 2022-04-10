#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    ll n;
    cin >> s >> n;

    ll len = s.length(), length = s.length();

    while (len < n) {
        len *= 2;
    }

    while (n > length) {
        while (len >= n) {
            len /= 2;
        }
        n -= len;
        if (n != 1) {
            n--;
        } else {
            n = len;
        }
    }
    cout << s[n - 1] << endl;
    return 0;
}