#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  double M;
  int T;
  int X;

  cin >> M >> T >> X;
  double price;
  price = ((T + X) / 100.0 + 1) * M;
  cout << "The final price of the meal is $" << round(price) << "." << endl;
  return 0;
}
