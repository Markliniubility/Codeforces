// #include <bits/stdc++.h>

// using namespace std;

// #define endl '\n'
// #define ll long long

// double dp[3005][3005];
// double kill[3005];
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int N, L; double p;
//   cin >> N >> L >> p;

//   double p_h = 1 - p;
//   dp[N][0] = 1; // dp[k][j] is have k left; the know j-th tile, 
//   for (int i = N - 1; i >= 0; i++) {
//     double prob = pow(p, i);
//     kill[i] = prob;
//     dp[i][0] = dp[i + 1][0] * prob;
//   }

//   for (int k = N; k >= 0; k--) {
//     for (int i = 0; i < L; i++) {
//       double prob = kill[k];
//       dp[k - 1][i] += prob * dp[k][i];
//       dp[k][i + 1] += (1 - prob) * 0.5 * dp[k][i];
//       dp[k - 1][i + 1] += (1 - prob) * 0.5 * dp[k][i];
//     }
//   }

//   bool res = 0;
//   for (int i = 0; i <= N; i++) {
//     res += 
//   }

//   cout << "NO" << endl;
//   return 0;
// }

#include <bits/stdc++.h> 
using namespace std; 
using namespace std; 
#define endl '\n' 
#define ll long long 
int order[100010]; 
int main() { 
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int n, k, m; 
  cin >> n >> k >> m; 
  vector< set<int> > alli(n + 1); 
  for (int i = 1; i <= m; i++) { 
    int a1, a2; 
    cin >> a1 >> a2; 
    alli.at(a1).insert(a2); 
    alli.at(a2).insert(a1); 
  } 
  queue<int> q; 
  for (int i = 1; i <= n; i++) { 
    order[i] = alli.at(i).size(); 
    if (order[i] == 1 || order[i] == 0) { 
      q.push(i); 
    } 
  } 
  while (!q.empty()) { 
    int cur = q.front(); 
    if (cur == k) { 
      cout << "YES" << endl; 
      return 0; 
    } 
    q.pop(); 
    set<int> nei = alli.at(cur); 
    for (int next: nei) { 
      order[next]--; 
      if (order[next] == 1 || order[next] == 0) { 
        q.push(next); 
      } 
    } 
  } 
  cout << "NO" << endl; 
  return 0; 
} 
