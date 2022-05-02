#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

ll weights[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    
    int leftMost = N, rightMost = -1;
    while (h--) {
        string s;
        cin >> s;
        for (int i = 1; i <= w; i++) {
            char block = s[i - 1];
            if (block != '.') {
                weights[i]++;
                if (!h && leftMost == N) {
                    leftMost = i;
                }
                if (!h) {
                    rightMost = i;
                }
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= w; i++) {
        sum += weights[i];
    }

    double center = 0;
    for (int i = 1; i <= w; i++) {
        center += (double)weights[i] / sum * i;
    }
 
    // cout << leftMost << rightMost << endl;
    center = round(center);
    if (center <= rightMost && center >= leftMost) {
        cout << "balanced" << endl;
    } else if (center > rightMost) {
        cout << "right" << endl;
    } else {
        cout << "left" << endl;
    }
    
    return 0;

}