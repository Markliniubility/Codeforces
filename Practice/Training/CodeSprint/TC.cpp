#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int d, x, y, h;
  cin >> d >> x >> y >> h;

  double half_h = h / 2.0;

  double ad = sqrt(x * x + y * y);\
  double ac = sqrt(x * x + (y + half_h) * (y + half_h));
  
  double cq = half_h / ad * x;
  double dq = half_h / ad * y;
  double eo = cq * (d / (ad + dq));

  double pk = cq;
  double pd = dq;
  double of = pk * (d / (ad - pd));

  printf("%.6lf", eo + of);
  return 0;
}