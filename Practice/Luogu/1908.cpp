#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

void merge(vector<ll> &helper, vector<ll> &arr, int l, int r, ll &res) {
    if (l >= r) {
        return;
    }

    ll md = l + (r - l) / 2;
    merge(helper, arr, l, md, res);
    merge(helper, arr, md + 1, r, res);
    ll pt1 = l, pt2 = md + 1, i = 0;
    copy(arr.begin() + l, arr.begin() + r + 1, helper.begin() + l);
    while (pt1 <= md && pt2 <= r) {
        if (helper[pt1] > helper[pt2]) {
            res += (md - pt1 + 1);
            arr[l + i++] = helper[pt2++];
        } else {
            arr[l + i++] = helper[pt1++];
        }
    }

    while (pt1 <= md) {
        arr[l + i++] = helper[pt1++];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> helper(n);
    ll res = 0;
    merge(helper, arr, 0, n - 1, res);
    cout << res << endl;
    return 0;
}