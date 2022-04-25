#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > zeros, int i, unordered_set<int> visited, int n, bool &res) {
  if (visited.size() == n) {
    res = true;
    return;
  }
  if (i >= zeros.size() || res) {
    if (visited.size() == n) {
      res = true;
    }
    return;
  }

  dfs(zeros, i + 1, visited, n, res);
  for (int z: zeros[i]) {
    if (visited.find(z) == visited.end()) {
      visited.insert(z);
      dfs(zeros, i + 1, visited, n, res);
      visited.erase(z);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> m >> n >> k;
  vector< vector<int> > zeros(m);

  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost;
      cin >> cost;
      if (!cost) {
        zeros[i].push_back(j);
      }
    }
  }
  bool res = false;
  unordered_set<int> visited;
  dfs(zeros, 0, visited, n, res);

  cout << (res ? "yes" : "no") << endl;
  return 0;
}

