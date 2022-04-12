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
    char res[1000];

    int i = 0, rem = 0;
    while (i < a.length() && i < b.length()) {
        int numA = a[i] - '0';
        int numB = b[i] - '0';

        int sum = numA + numB + rem;
        rem = 0;
        if (sum >= 10) {
            rem = sum / 10;
            sum = sum % 10;
        }
        res[i++] = sum + '0';
    }

    while (i < a.length()) {
        int numA = a[i] - '0';

        int sum = numA + rem;
        rem = 0;
        if (sum >= 10) {
            rem = sum / 10;
            sum = sum % 10;
        }
        res[i++] = sum + '0';
    }

    while (i < b.length()) {
        int numA = b[i] - '0';

        int sum = numA + rem;
        rem = 0;
        if (sum >= 10) {
            rem = sum / 10;
            sum = sum % 10;
        }
        res[i++] = sum + '0';
    }

    if (rem > 0) {
        res[i++] = rem + '0';
    }
    
    while (i > 0) {
        cout << res[--i];
    }
    cout << endl;
    return 0;
}