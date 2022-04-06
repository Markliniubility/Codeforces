#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

bool valid(vector<int> s, int val, int limit) {
    int count = 0;
    for (int i = 1; i < s.size(); i++) {
        int jump = s.at(i) - s.at(i - 1), b = i - 1;
        if (jump >= val) continue;
        while (i + 1 < s.size() && jump < val) {
            jump = s.at(++i) - s.at(b);
        }
        count += i - b - 1;
        if (jump < val) return false;
    }
    return count <= limit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, n, m;
    cin >> L >> n >> m;
    vector<int> arr(n + 2);
    arr.at(0) = 0;
    arr.at(n + 1) = L;
    for (int i = 1; i <= n; i++) {
        cin >> arr.at(i);
    }

    int l = 1, r = L;
    while (l < r - 1) {
        int md = l + (r - l) / 2;
        bool f = valid(arr, md, m);
        if (f) {
            l = md;
        } else {
            r = md - 1;
        }
    }
    bool f = valid(arr, r, m);
    cout << (f ? r : l) << endl;
    return 0;
}

// Failure with Greedy Algorithms
// struct Node {
//     int len;
//     int index;
// };

// bool Compare(Node a, Node b) {
//     return a.len > b.len;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int L, n, m;
//     cin >> L >> n >> m;
//     vector<int> arr(n + 2);
//     arr.at(0) = 0;
//     arr.at(n + 1) = L;
//     for (int i = 1; i <= n; i++) {
//         cin >> arr.at(i);
//     }

//     vector<int> dist(n + 1);
//     for (int i = 0; i <= n; i++) {
//         dist.at(i) = arr.at(i + 1) - arr.at(i);
//     }

//     std::priority_queue<Node, vector<Node>, decltype(&Compare)> pq(Compare); // min length, index
//     for (int i = 0; i < n + 1; i++) {
//         Node temp = {dist.at(i), i};
//         pq.push(temp);
//     }

//     while (m-- && !pq.empty()) {
//         Node top = pq.top();
//         pq.pop();
//         int len = top.len, index = top.index;
//         if (dist.at(index) != len) {
//             m++;
//             continue;
//         }
//         if (index == 0) {
//             dist.at(index + 1) +=  dist.at(index);
//             dist.at(index) = N;
//             Node temp = {dist.at(index + 1), index + 1};
//             pq.push(temp);
//         } else if (index == n) {
//             dist.at(index - 1) +=  dist.at(index);
//             dist.at(index) = N;
//             Node temp = {dist.at(index - 1), index - 1};
//             pq.push(temp);
//         } else {
//             int left = index - 1, right = index + 1;
//             while (left >= 0 && dist.at(left) == N) {
//                 left--;
//             }
//             while (right <= n && dist.at(right) == N) {
//                 right++;
//             }
//             if (dist.at(left) < dist.at(right)) {
//                 dist.at(left) +=  dist.at(index);
//                 dist.at(index) = N;
//                 Node temp = {dist.at(left), left};
//                 pq.push(temp);
//             } else {
//                 dist.at(right) +=  dist.at(index);
//                 dist.at(index) = N;
//                 Node temp = {dist.at(right), right};
//                 pq.push(temp);
//             }
//         }
//     }
//     int res = N;
//     for (int i: dist) {
//         res = min(i, res);
//     }
//     cout << res << endl;
//     return 0;
// }