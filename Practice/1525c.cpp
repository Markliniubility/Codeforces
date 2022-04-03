#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 10);
    vector<char> a(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> x[i]; 
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> f(n, -1), p(n);
    iota(p.begin(), p.end(), 0);

    sort(p.begin(), p.end(), [&](int a, int b) {
        return x[a] < x[b];
    });

    for (int k = 0; k < 2; k++) {
        vector<int> temp;
        for (int i: p) {
            if (x[i] % 2 != k) {
                continue;
            }
            if (a[i] == 'L' && !temp.empty() && a[temp.back()] == 'R') {
                f[i] = f[temp.back()] = (x[i] - x[temp.back()]) / 2;
                temp.pop_back();
            } else {
                temp.push_back(i);
            }
        }

        int md = partition_point(temp.begin(), temp.end(), [&](int i) {
            return a[i] == 'L';
        }) - temp.begin();
        
        int size = temp.size();
    
        for (int i = 0; i + 1 < md; i += 2) {
            f[temp[i]] = f[temp[i + 1]] = (x[temp[i]] + x[temp[i + 1]]) / 2;
        }

        for (int i = size - 1; i - 1 >= md; i -= 2) {
            f[temp[i]] = f[temp[i - 1]] = ((m - x[temp[i]]) + (m - x[temp[i - 1]])) / 2;
        }
        
        // final possibility
        if (md % 2 == 1 && (size - md) % 2 == 1) {
            f[temp[md]] = f[temp[md - 1]] = (m + x[temp[md - 1]] + (m - x[temp[md]])) / 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    cout << "\n";
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