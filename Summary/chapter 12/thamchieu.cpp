#include <iostream>

using namespace std;

int main() {
  // Khai báo biến `x` và tham chiếu `ref` tham chiếu đến `x`
  int x = 10;
  int& ref = x;

  // In giá trị ban đầu của `x`
  cout << "Giá trị ban đầu của x: " << x << endl;

  // Thay đổi giá trị của `x` thông qua tham chiếu `ref`
  ref = 20;

  // In giá trị mới của `x` (được thay đổi qua tham chiếu)
  cout << "Giá trị mới của x sau khi thay đổi qua tham chiếu: " << x << endl;

  // Thay đổi giá trị của `x` trực tiếp
  x = 30;

  // In giá trị mới nhất của `x` (được thay đổi trực tiếp)
  cout << "Giá trị mới nhất của x: " << x << endl;

  return 0;
}
