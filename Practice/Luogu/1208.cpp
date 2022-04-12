#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

// First Trial: 88/100. WA on #2 (Output: 0)
// AC

struct Node {
    int price;
    int amount;
};

bool cmp(Node a, Node b) {
    return a.price < b.price;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Node arr[m];
    int cost = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].price;
        cin >> arr[i].amount;
    }
    
    sort(arr, arr + m, cmp);

    for (int i = 0; i < m; i++) {
        int p = arr[i].price, q = arr[i].amount;
        if (q >= n) {
            cost += p * n;
            break;
        } else {
            cost += p * q;
            n -= q;
        }
    }

    cout << cost << endl;
    return 0;
}