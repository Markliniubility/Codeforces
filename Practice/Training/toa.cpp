#include <bits/stdc++.h>

using namespace std;

void bfs(vector< vector<int> >& connection, vector<bool>& v, int i) {
    if (v.at(i)) {
        return;
    }
    v[i] = true;
    vector<int> conn = connection.at(i);
    for (int f: conn) {
        bfs(connection, v, f);
    }
}

int cntgroup(vector<string> r) {
    int n = r.size();
    vector< vector<int> > connection(n);
    vector<bool> visited(n);

    for (int i = 0; i < n; i++) {
        string s = r.at(i);
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                connection.at(i).push_back(j);
            }
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (visited.at(i)) {
            continue;
        }
        res++;
        bfs(connection, visited, i);
    }

    return res;
}

int main() {
    vector<string> test;
    test.push_back("1000");
    test.push_back("0100");
    test.push_back("0010");
    test.push_back("0001");
    int res = cntgroup(test);
    cout << res << endl;
}