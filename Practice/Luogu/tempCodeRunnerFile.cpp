#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll N=3000;
const ll mod=998244353;
const ll inf=2000000000000000001;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, p;
    cin >> s >> p;
    int n = p.length();
    int pi[n] {};

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (p[j] != p[i] && j != 0) {
            j = pi[j - 1];
        }
        if (p[j] == p[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    vector<int> res;
    int border = 0;
    int pt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == p[pt]) {
            pt++;
            if (pt == n) {
                res.push_back(i - n + 2);
                pt = pi[pt - 1];
            }
        } else {
            pt = pi[pt - 1];
        }
    }

    for (int i: res) {
        cout << i << endl;
    }
    for (int i: pi) {
        cout << i << " ";
    }

    return 0;
}