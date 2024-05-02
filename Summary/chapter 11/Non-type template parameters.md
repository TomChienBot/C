[Non-type template parameters](https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/)

1. Non-type template parameters

(non-type template parameter) trong C++ là một tham số của mẫu (template) có kiểu cố định và được truyền vào dưới dạng đối số mẫu. Non-type template parameters có thể là bất kỳ trong các loại sau:

Kiểu số nguyên (integral type).
Kiểu liệt kê (enumeration type).
std::nullptr_t.
Kiểu số thực (floating point type) (kể từ C++20).
Con trỏ hoặc tham chiếu đến đối tượng.
Con trỏ hoặc tham chiếu đến hàm.
Con trỏ hoặc tham chiếu đến hàm thành viên.
Kiểu lớp chữ số (literal class type) (kể từ C++20).

1. Defining our own non-type template parameters

ví dụ:

#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print()
{
    std::cout << N << '\n'; // use value of N here
}

int main()
{
    print<5>(); // 5 is our non-type template argument

    return 0;
}

Best practice:

Sử dụng N làm tên của tham số mẫu không phải kiểu int.

2. What are non-type template parameters useful for?

key insight
Các tham số mẫu không phải kiểu được sử dụng chủ yếu khi chúng ta cần chuyển các giá trị constexpr cho các hàm (hoặc kiểu lớp) để chúng có thể được sử dụng trong các ngữ cảnh yêu cầu biểu thức không đổi. Loại lớp std::bitset sử dụng tham số mẫu không phải loại để xác định số bit cần lưu trữ vì số bit phải là giá trị constexpr.
