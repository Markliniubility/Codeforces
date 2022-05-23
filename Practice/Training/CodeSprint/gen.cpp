
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
  srand((unsigned)time(0));
  int num = 1000000;
  int T = 1000000;
  cout << num << " " << T << endl;
  for (int i = 0; i < num; i++) {
    cout << 1000000 << endl;
  }
  return 0;
}