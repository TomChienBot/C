[Default arguments](https://www.learncpp.com/cpp-tutorial/default-arguments/)

Đối số mặc định là giá trị mặc định được cung cấp cho tham số hàm

ví dụ:

void print(int x, int y=10) // 10 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

khi gọi hàm, nếu người gọi không cung cấp đối số, giá trị đối số mặc định sẽ được sử dụng.

1. When to use default arguments

Đối số mặc định là một lựa chọn tuyệt vời khi hàm cần một giá trị có giá trị mặc định hợp lý

2. Multiple default arguments

Một hàm có thể có nhiều tham số với các đối số mặc định
ví dụ:

#include <iostream>

void print(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print(1, 2, 3); // all explicit arguments
    print(1, 2); // rightmost argument defaulted
    print(1); // two rightmost arguments defaulted
    print(); // all arguments defaulted

    return 0;
}

3. Default arguments can not be redeclared

Sau khi được khai báo, một đối số mặc định không thể được khai báo lại (trong cùng một tệp).

ví dụ:

#include <iostream>

void print(int x, int y=4); // forward declaration

void print(int x, int y=4) // error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

Best practice:

Nếu hàm có một khai báo chuyển tiếp (đặc biệt là một khai báo trong tệp tiêu đề), hãy đặt đối số mặc định ở đó. Nếu không, hãy đặt đối số mặc định trong định nghĩa hàm.

4. Default arguments and function overloading

ví dụ:

void print(int x);
void print(int x, int y = 10);
void print(int x, double y = 20.5);


print(1, 2); // will resolve to print(int, int)
print(1, 2.5); // will resolve to print(int, double)
print(1); // ambiguous function call

Trong trường hợp cuối cùng, trình biên dịch không thể biết liệu print(1) nên phân giải thành print(int) hay một trong hai hàm trong đó tham số thứ hai có giá trị mặc định. Kết quả là một lệnh gọi hàm không rõ ràng.