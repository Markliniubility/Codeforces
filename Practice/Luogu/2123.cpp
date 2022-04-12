#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

// First Trail: 80. Lost Points for the loss of transitivity
// Notes of solution in my ipad and Luogu

struct Node {
    ll a;
    ll b;
} arr[30000];

ll money[30000];

bool cmp(Node n1, Node n2) {
    int d1 = (n1.a - n1.b) / abs(n1.a - n1.b);
    int d2 = (n2.a - n2.b) / abs(n2.a - n2.b);
    if (d1 < d2) {
        return true;
    }
    if (d1 > d2) {
        return false;
    }
    if (d1 == -1) {
        return n1.a < n2.a;
    } else {
        return n1.b > n2.b;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }
    
    sort(arr, arr + n, cmp);

    money[0] = arr[0].a + arr[0].b;
    ll sum = arr[0].a;

    for (int i = 1; i < n; i++) {
        sum += arr[i].a;
        money[i] = max(sum, money[i - 1]) + arr[i].b;
    }

    cout << money[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}