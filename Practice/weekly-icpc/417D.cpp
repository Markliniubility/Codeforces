#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int sq(int x) {
    return x * x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cx, cy, n;
    cin >> cx >> cy >> n;
    vector<int> distances(n);
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        int dist2 = sq(abs(cx - x)) + sq(abs(cy - y));
        int dist = sqrt(dist2) - r;
        dist = max(dist, 0);
        distances[i - 1] = dist;
    }
    sort(distances.begin(), distances.end());
    cout << distances[2] << endl;
    return 0;

}