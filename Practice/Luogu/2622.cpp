#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

ll a[200][200];
ll open[200], close[200];
int n, m;
int ans = 0;
struct Node{ll s, step;};
bool visited[191981000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        ll op = 0, cl = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cl |= 1 << j;
            } else if (a[i][j] == -1) {
                op |= 1 << j;
            }
        }
        open[i] = op;
        close[i] = cl;
    }
    
    queue<Node> q;
    q.push((Node){(1 << n) - 1, 0});
    visited[(1 << n) - 1] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        ll state = cur.s, step = cur.step;
        for (int i = 0; i < m; i++) {
            ll next = state;
            next |= open[i];
            next &= ~close[i]; // THIS IS THE FUCKING KEY WHY I WAS WA
            if (!next) {
                cout << step + 1;
                return 0;
            }
            if (!visited[next]) {
                q.push((Node){next, step + 1});
                visited[next] = true;
            }
        }
    }
    cout << -1;
    return 0;
}
