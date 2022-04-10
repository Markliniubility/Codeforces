#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

ll rec[N];

int valid(ll n, ll k, ll l) {
    ll lines = 0, count = 0;
    for (int i = 0; i < l; i++) {
        lines += rec[i];
        if (lines < 0) {
            lines = 0;
        }
        if (lines >= n) {
            lines = 0;
            count++;
        }
    }
    // if 1, it means n is too small
    // if -1, it means n is too large
    // if zero, it menas n is just right
    if (count - k > 0) {
        return 1;
    } else if (count - k < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, k;
    cin >> l >> k;

    for (ll i = 0; i < l; i++) {
        cin >> rec[i];
    }

    // find the min first
    ll left = 1, right = inf;
    while (left < right - 1) {
        ll md = left + (right - left) / 2;
        ll diff = valid(md, k, l);
        if (diff < 0) {
            right = md - 1;
        } else if (diff == 0) {
            right = md;
        } else {
            left = md;
        }
    }
    // cout << valid(7, k, l) << endl;
    ll min = valid(left, k, l) == 0 ? left: right;
    // find the max
    left = 1; right = inf;
    while (left < right - 1) {
        ll md = left + (right - left) / 2;
        ll diff = valid(md, k, l);
        if (diff > 0) {
            left = md + 1;
        } else if (diff == 0) {
            left = md;
        } else {
            right = md;
        }
    }
    ll max = valid(right, k, l) == 0 ? right: left;
    // compare min and max, get result
    if (max >= min && valid(min, k, l) == 0 && min > 0) {
        cout << min << " " << max << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;

}