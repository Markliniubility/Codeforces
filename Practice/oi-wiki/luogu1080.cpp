#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// THIS IS NOT an AC solution
// because 

const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;

struct uv {
    int a, b;
    bool operator<(const uv &x) const {
      // int max1 = max(1/this->b, this->a/x.b);
      // int max2 = max(1/x.b, x.a/this->b);
      // compare max1 and max2
      return max(x.b, a * b) < max(b, x.a * x.b);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int num;
  cin >> num;
  vector<uv> v(num + 1);
  for (int i = 0; i <= num; i++) {
    int a, b;
    cin >> a >> b;
    uv p = {a, b};
    v[i] = p;
  }
  sort(v.begin() + 1, v.end());
  
  int prev = v.at(0).a;
  int res = 0;
  for (int i = 1; i <= num; i++) {
    res = max(res, prev / v.at(i).b);
    prev *= v.at(i).a;
  }
  cout << res << "\n";
  return 0;
}