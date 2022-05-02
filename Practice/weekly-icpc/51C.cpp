#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

set<int> primes;
bool isPrime[32000];

void solve(int num) {
    vector< vector<int> > res;
    for (int i = 2; i <= num / 2; i++) {
        int rem = num - i;
        if (primes.find(i) != primes.end() && primes.find(rem) != primes.end()) {
            vector<int> pair{i, rem};
            res.push_back(pair);
        }
    }
    
    cout << num << " has " << res.size() << " representation(s)" << endl;
    for (vector<int> v: res) {
        cout << v[0] << "+" << v[1] << endl;
    }
    cout << endl;
}

void findPrimes() {
    // only from zero to 32000
    for (int i = 2; i <= 32000; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= 32000; i++) {
        if (isPrime[i]) {
            for (int j = i; j * i <= 32000; j++) {
                isPrime[j * i] = false;
            }
        }
    }

    for (int i = 2; i <= 32000; i++) {
        if (isPrime[i]) {
            primes.insert(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    
    findPrimes();

    for (int i = 1; i <= n; i++) {
        solve(nums[i]);
    }

    return 0;

}