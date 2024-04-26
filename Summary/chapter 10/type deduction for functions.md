[Type deduction for functions](https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/)

int add(int x, int y)
{
    return x + y;
}

Khi hàm này được biên dịch, trình biên dịch sẽ xác định rằng x + y ước lượng thành int, sau đó đảm bảo rằng kiểu giá trị trả về khớp với kiểu trả về được khai báo của hàm

Vì trình biên dịch đã phải suy ra kiểu trả về từ câu lệnh trả về nên trong C++ 14, từ khóa auto đã được mở rộng để thực hiện suy luận ra kiểu trả về của hàm. Điều này hoạt động bằng cách sử dụng từ khóa auto thay cho kiểu trả về của hàm.

Khi sử dụng kiểu trả về tự động, tất cả các câu lệnh trả về trong hàm phải trả về các giá trị cùng loại, nếu không sẽ xảy ra lỗi. Ví dụ:

auto someFcn(bool b)
{
    if (b)
        return 5; // return type int
    else
        return 6.7; // return type double
}

BEST PRACTICE:
Ưu tiên các kiểu trả về rõ ràng hơn là sử dụng kiểu trả về deduction về của hàm đối với các hàm thông thường. 

1. Trailing return type syntax

Từ khóa auto cũng có thể được sử dụng để khai báo các hàm bằng cách sử dụng một trailing return syntax ví dụ:

auto add(int x, int y) -> int
{
  return (x + y);
}

Trong trường hợp này, auto không thực hiện khấu trừ kiểu -- nó chỉ là một phần của cú pháp sử dụng kiểu trả về theo sau.

2. Type deduction can’t be used for function parameter types

#include <iostream>

void addAndPrint(auto x, auto y)
{
    std::cout << x + y << '\n';
}

int main()
{
    addAndPrint(2, 3); // case 1: call addAndPrint with int parameters
    addAndPrint(4.5, 6.7); // case 2: call addAndPrint with double parameters

    return 0;
}

Việc SUY LUẬN không hoạt động đối với các tham số hàm và trước C++ 20, chương trình trên sẽ không biên dịch