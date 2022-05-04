#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

queue<string> q;
set<ll> visited;
ll base = 31;

ll hashcode(string &s) {
  ll res = 0;
  for (int i = 0; i < 9; i++) {
    res = res * base + (ll)(s[i] - 'a');
  }
  return res;
}

void helper(string &s) {
  int loc = -1;
  for (int i = 0; i < 9; i++) {
    if (s[i] == '0') {
      loc = i;
      break;
    }
  }

  if (loc + 3 < 9) {
    swap(s[loc], s[loc + 3]);
    string s1(s);
    ll h = hashcode(s1);
    if (visited.find(h) == visited.end()) {
      q.push(s1);
      visited.insert(h);
    }
    swap(s[loc], s[loc + 3]);
  }

  if (loc - 3 >= 0) {
    swap(s[loc], s[loc - 3]);
    string s1(s);
    ll h = hashcode(s1);
    if (visited.find(h) == visited.end()) {
      q.push(s1);
      visited.insert(h);
    }
    swap(s[loc], s[loc - 3]);
  }

  if ((loc - 1) % 3 != 2 && loc - 1 >= 0) {
    swap(s[loc], s[loc - 1]);
    string s1(s);
    ll h = hashcode(s1);
    if (visited.find(h) == visited.end()) {
      q.push(s1);
      visited.insert(h);
    }
    swap(s[loc], s[loc - 1]);
  }
  if ((loc + 1) % 3 && loc + 1 < 9) {
    swap(s[loc], s[loc + 1]);
    string s1(s);
    ll h = hashcode(s1);
    if (visited.find(h) == visited.end()) {
      q.push(s1);
      visited.insert(h);
    }
    swap(s[loc], s[loc + 1]);
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  // s = "." + s;
  int step = 0;
  string des("123804765");
  q.push(s);
  while (!q.empty()) {
    int size = q.size();
    bool founded = false;
    while (size--) {
      string cur = q.front();
      q.pop();
      if (cur == des) {
        founded = true;
        break;
      }
      helper(cur);
    }
    if (founded) break;
    step++;
  }
  cout << step << endl;
  return 0;
}