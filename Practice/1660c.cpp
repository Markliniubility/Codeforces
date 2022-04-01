#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;


void solve() {
    string s;
    cin >> s;
    int len = s.length();

    vector<int> dp(len + 100);
    vector<int> last(len + 100);

    for (int i = 0; i < 26; i++) last[i] = 0;

    for (int i = 1; i <= len; i++) {
        dp[i] = dp[i - 1]; 
        char cur = s[i - 1];
        int prev = last[cur - 'a'];
        if (prev != 0) {
            dp[i] = max(dp[i], dp[prev - 1] + 2);
        }
        last[cur - 'a'] = i;
    }

    cout << len - dp[len] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}