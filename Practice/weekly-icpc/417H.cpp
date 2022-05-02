#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int val[N];
int increase[N];
int decrease[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, n, m;
    cin >> num >> n >> m;

    for (int i = 1; i <= num; i++) {
        cin >> val[i];
    }
    int inc = 1, previousV = -1, dec = 1, previousP = -1;
    increase[1] = decrease[1] = 1;
    for (int i = 2; i <= num; i++) {
        if (val[i] > val[i - 1]) {
            inc++;
            dec = 1;
        } else {
            dec++;
            inc = 1;
        }
        increase[i] = inc;
        decrease[i] = dec;
    }
    inc = dec = 1;
    increase[num] = decrease[num] = 1;
    for (int i = num - 1; i >= 1; i--) {
        if (val[i] > val[i + 1]) {
            inc++;
            dec = 1;
        } else {
            dec++;
            inc = 1;
        }
        increase[i] = min(increase[i], inc);
        decrease[i] = min(decrease[i], dec);
    }

    int resP = 0, resV = 0;
    for (int i = 1; i <= num; i++) {
        // cout << "increase: " << i << " " << increase[i] << endl;
        // cout << "decrease: " << i << " " << decrease[i] << endl;
        if (increase[i] >= n) {
            resP++;
        } else if (decrease[i] >= m) {
            resV++;
        }
    }
    cout << resP << " " << resV << endl;
    return 0;

}