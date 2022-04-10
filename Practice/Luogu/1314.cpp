#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

// Aside from the simple binary search, this question also 
// requires usage of prefix some to speed up the measure process.
// More specficially, we maintain two pre-fix sum arrays p and q on each measurements.
// p[i] represents how many stones weigh above W in range [0, i)
// Similarly for q.

// For each measurements, we need to update the prefix sum arrays O(n).
// Then, each range check is only O(1). The total TC for each measurement
// is reduced to O(m + n) from O(nm).

int p[N], q[N];

ll measure(vector<vector<ll>> stones, vector<vector<ll>> rs, ll W) {
    ll res = 0;
    for (ll i = 0; i < stones.size(); i++) {
        if (stones[i][0] >= W) {
            p[i + 1] = p[i] + 1;
            q[i + 1] = q[i] + stones.at(i).at(1);
        } else {
            p[i + 1] = p[i];
            q[i + 1] = q[i];
        }
    }
    for (vector<ll> r: rs) {
        ll left = r.at(0) - 1, right = r.at(1) - 1;
        // [0, right] - [0, left - 1]
        res += (q[right + 1] - q[left]) * (p[right + 1] - p[left]);
    }
    return res;
}

// The following function doesn't use prefix sum and is too slow.
// ll measure(vector<vector<ll>> stones, vector<vector<ll>> rs, ll W) {
//     ll res = 0;
//     for (vector<ll> r: rs) {
//         ll left = r.at(0) - 1, right = r.at(1) - 1;
//         ll sum1 = 0, sum2 = 0;
//         for (ll i = left; i <= right; i++) {
//             if (stones.at(i).at(0) >= W) {
//                 sum1 += 1;
//                 sum2 += stones.at(i).at(1);
//             }
//         }
//         res += sum1 * sum2;
//     }
//     return res;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, s;
    cin >> n >> m >> s;
    
    ll left = 0, right = 0;
    vector<vector<ll>> stones(n);
    for (ll i = 0; i < n; i++) {
        vector<ll> stone(2); // w, v
        cin >> stone.at(0) >> stone.at(1);
        right = max(right, stone.at(1));
        stones.at(i) = stone;
    }

    vector<vector<ll>> rs(m);
    for (ll i = 0; i < m; i++) {
        vector<ll> r(2);
        cin >> r.at(0) >> r.at(1);
        rs.at(i) = r;
    }

    while (left < right - 1) {
        ll mid = left + (right - left) / 2;
        ll val = measure(stones, rs, mid);
        if (val > s) {
            left = mid;
        } else if (val < s) {
            right = mid;
        } else {
            cout << 0 << endl;
            return 0;
        }
    } 
    ll ml = measure(stones, rs, left);
    ll mr = measure(stones, rs, right);
    cout << min(abs(ml - s), abs(mr - s)) << endl;
}