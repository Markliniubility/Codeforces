#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
  string s;
  unordered_set<char> c_set;
  vector<char> result(5, 0);

  cout << "? abcde\n";
  cout.flush();
  cin >> s;
  for (int i = 0; i < 5; i++) {
    char base = 'a' + i;
    if (s[i] == '2' || s[i] == '1') {
      c_set.insert(base);
    }
  }

  cout << "? fghij\n";
  cout.flush();
  cin >> s;
  for (int i = 0; i < 5; i++) {
    char base = 'f' + i;
    if (s[i] == '2' || s[i] == '1') {
      c_set.insert(base);
    }
  }

  cout << "? klmno\n";
  cout.flush();
  cin >> s;
  for (int i = 0; i < 5; i++) {
    char base = 'k' + i;
    if (s[i] == '2' || s[i] == '1') {
      c_set.insert(base);
    }
  }

  cout << "? pqrst\n";
  cout.flush();
  cin >> s;
  for (int i = 0; i < 5; i++) {
    char base = 'p' + i;
    if (s[i] == '2' || s[i] == '1') {
      c_set.insert(base);
    }
  }

  cout << "? uvwxy\n";
  cout.flush();
  cin >> s;
  for (int i = 0; i < 5; i++) {
    char base = 'u' + i;
    if (s[i] == '2' || s[i] == '1') {
      c_set.insert(base);
    }
  }

  int fixed = 0;
  vector<char> c_list(c_set.begin(), c_set.end());
  for (int t = 0; t < min((int) c_list.size(), 4); t++) {
    char c = c_list[t];

    cout << "? ";
    for (int i = 0; i < 5; i++) {
      cout << c;
    }
    cout << '\n';
    cout.flush();

    string s;
    cin >> s;
    for (int i = 0; i < 5; i++) {
      if (s[i] == '2') {
        fixed += 1;
        result[i] = c;
      }
    }
  }

  if (fixed < 5 && c_list.size() < 5) {
    for (int i = 0; i < 5; i++) {
      if (result[i] == 0) {
        result[i] = 'z';
      }
    }
  }

  if (fixed < 5 && c_list.size() == 5) {
    for (int i = 0; i < 5; i++) {
      if (result[i] == 0) {
        result[i] = c_list[4];
      }
    }
  }

  cout << "? ";
  for (char c: result) {
    cout << c;
  }
  cout << '\n';
  cout.flush();
  return 0;
}