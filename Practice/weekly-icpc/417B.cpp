#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

ll rec[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double totalf, p1f, p2f;
    cin >> totalf >> p1f >> p2f;
    ll total = totalf * 1000, p1 = p1f * 1000, p2 = p2f * 1000;
    ll q1 = 0;

    bool printed = false;
    while (true) {
        if (q1 * p1 > total) {
            break;
        }
        ll q2 = (total - p1 * q1) / p2;
        // cout << q2 << endl;
        if ((total - p1 * q1) % p2 == 0) {
            printed = true;
            cout << q1 << " " << q2 << endl;
        }
        q1 += 1;
    }

    if (!printed) {
        cout << "none" << endl;
    }
    return 0;

}