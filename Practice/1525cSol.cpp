#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    std::vector<char> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector<int> f(n, -1), p(n);
    std::iota(p.begin(), p.end(), 0);

    std::sort(p.begin(), p.end(), [&](int i, int j) { return x[i] < x[j]; });
    // p[i] stands for the location order of the i-th robot

    for (int i = 0; i < n; i++) {
        cout << p[i] << "\n";
    }
    
    for (int v = 0; v < 2; v++) {
        std::vector<int> a;
        for (auto i : p) {
            // loop through the robot according to location order.
            if (x[i] % 2 != v) {
                // Because the only possible collusion is for the position with the same parity
                continue;
            }
            // R ->> <<- L explosion case
            if (s[i] == 'L' && !a.empty() && s[a.back()] == 'R') {
                f[i] = f[a.back()] = (x[i] - x[a.back()]) / 2; // Time it needs for reaching explosion
                a.pop_back();
            } else {
                a.push_back(i);
            }
        }
        
        int md = std::partition_point(a.begin(), a.end(), [&](auto x) { return s[x] == 'L'; }) - a.begin();
        for (int i: a) {
            cout << i << " ";
        }
        cout << "\n";
        cout << md << "\n";
        int k = a.size();
        
        for (int i = 0; i + 1 < md; i += 2) {
            // <<- L,L and collide
            f[a[i]] = f[a[i + 1]] = (x[a[i]] + x[a[i + 1]]) / 2;
        }
        for (int i = 0; i + 1 < k - md; i += 2) {
            // R, R -> Collide
            f[a[k - 1 - i]] = f[a[k - 2 - i]] = m - (x[a[k - 1 - i]] + x[a[k - 2 - i]]) / 2;
        }
        if (md % 2 == 1 && k % 2 == 0) {
            // possible with only two left and collusion
            f[a[md - 1]] = f[a[md]] = m - (x[a[md]] - x[a[md - 1]]) / 2;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << f[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}