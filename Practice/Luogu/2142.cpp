#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int res[50000];
    
    int l1 = a.length(), l2 = b.length(), length = 0;
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            int num1 = a[i] - '0', num2 = b[j] - '0';
            int prod = num1 * num2, rem = 0;
            int k = j + i;
            while (prod > 0) {
                int digit = prod % 10;
                prod /= 10;
                res[k] += digit + rem;
                rem = 0;
                if (res[k] >= 10) {
                    rem = res[k] / 10;
                    res[k] %= 10;
                }
                k++;
            }
            while (rem != 0) {
                res[k] += rem;
                rem = 0;
                if (res[k] >= 10) {
                    rem = res[k] / 10;
                    res[k] %= 10;
                }
                k++;
            }
            length = max(length, k);
        }
    }

    while (length > 0) {
        cout << res[--length];
    }
    cout << endl;
    return 0;
}