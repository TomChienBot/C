[Introduction to function overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/)

int add(int x, int y)
{
    return x + y;
}

Hàm này cộng hai số nguyên và trả về một kết quả là số nguyên. Tuy nhiên, nếu chúng ta cũng muốn một hàm có thể cộng hai số thập phân thì sao? Hàm add() này không phù hợp vì mọi tham số dấu phẩy động sẽ được chuyển đổi thành số nguyên, khiến các đối số thập phân mất giá trị phân số của chúng.

Cách xử lí là có thể tạo thêm 1 hàm số thập phân với cái tên khác.

1. Introduction to function overloading

Nạp chồng hàm cho phép tạo ra nhiều hàm với cùng tên, miễn là hàm có kiểu tham số khác nhau.

Mỗi hàm có chung một tên (trong cùng phạm vi) được gọi là hàm quá tải (đôi khi được gọi tắt là quá tải).

Ví dụ:
int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    return 0;
}

Trương trình vẫn có thể biên dịch miễn là trình biên dịch có thể nhận ra sự khác nhau của các hàm ghi đè. Nếu các hàm ghi đè không thể phân biệt đc, biên dịch sẽ ra kết quả lỗi.

2. Introduction to overload resolution

khi gọi hàm tới một hàm đã bị overloaded, trình biên dịch sẽ cố gắng khớp lệnh gọi hàm với hàm overload trên các đối số được sử dụng trong lệnh gọi hàm.

Ví dụ:

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}

Kết quả :
3
4.6

Với đối số là số nguyên, trình biên dịch sẽ gọi hàm add(int, int), Nếu đối số là số thập phân trình biên dịch sẽ gọi hàm add(double, double).

3. Making it compile
Mỗi hàm overload phải khác nhau

BEST PRACTICE:
Sử dụng nạp chồng hàm để làm cho chương trình của bạn đơn giản hơn.