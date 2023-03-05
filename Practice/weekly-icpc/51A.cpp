#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

int divisor[105][1000005];
int nums[105];
int maxD = 2;

void primeFactorization(int num, int index) {
    for (int i = 2; i * i <= num; ++i) {
        while (num % i == 0) {
            num /= i;
            divisor[index][i]++;
            divisor[0][i]++;
        }
        maxD = max(maxD, i);
    }
    if (num != 1) {
        divisor[index][num]++;
        divisor[0][num]++;
        maxD = max(maxD, num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    // vector< vector<int> > factorList(n + 10);
    for (int i = 1; i <= n; i++) {
        primeFactorization(nums[i], i);
    }

    ll score = 1, opNum = 0;
    for (ll i = 2; i <= maxD; i++) {
        int numOfFactors = divisor[0][i];
        int mean = numOfFactors / n;
        int rem = numOfFactors % n;
        if (!mean) continue;
        for (int k = 0; k < mean; k++) score *= i;
        for (int j = 1; j <= n; j++) {
            int count = divisor[j][i];
            if (count > mean) {
                opNum += count - mean;
                // cout << count - mean << endl;
            }
        }
        opNum -= rem;
    }

    cout << score << " " << opNum << endl;
    
    return 0;

}