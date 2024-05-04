[Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)

char x {}; // chars use 1 byte of memory

Đơn giản hóa một chút, khi định nghĩa này được thực thi, một phần bộ nhớ từ RAM sẽ được gán cho đối tượng này

Ví dụ: Biến x được gán địa chỉ bộ nhớ là 140. Bất cứ khi nào cần sử dụng biến x, chương trình sẽ đi đến địa chỉ bộ nhớ 140 để truy cập giá trị lưu trữ ở đó.

Trình biên dịch đảm nhiệm tất cả việc đánh địa chỉ.

1. The address-of operator (&)

#include <iostream>

int main()
{

    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    return 0;

}

Trong ví dụ trên, chúng ta sử dụng toán tử địa chỉ (&) để lấy địa chỉ được gán cho biến x và in địa chỉ đó ra màn hình. Địa chỉ được in ra là giá trị hexa.

2. The dereference operator (*)

Toán tử quy định (*) (đôi khi còn được gọi là toán tử gián tiếp) trả về giá trị tại một địa chỉ đã cho như là lvalue

#include <iostream>

int main()
{

    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;

}
Key insight

Cho một địa chỉ bộ nhớ, chúng ta có thể sử dụng toán tử quy chiếu (*) để lấy giá trị tại địa chỉ đó (dưới dạng giá trị lvalue). Toán tử địa chỉ của (&) và toán tử quy định (*) hoạt động như đối lập nhau:

    Toán tử lấy địa chỉ (&):

    Trả về địa chỉ bộ nhớ của một biến.
    Địa chỉ này là một số đại diện cho vị trí lưu trữ biến đó trong bộ nhớ.
    Bạn có thể tưởng tượng toán tử lấy địa chỉ giống như việc hỏi "Biến này được lưu trữ ở đâu trong thư viện?".

    Toán tử giải tham chiếu (*):

    Được sử dụng với con trỏ để truy cập giá trị được lưu trữ tại địa chỉ mà con trỏ đang trỏ đến.
    Nó giống như việc nói "Cho tôi xem thứ gì được lưu trữ tại địa chỉ này".

3. Pointers

Con trỏ là đối tượng chưa địa chỉ bộ nhớ (thường là 1 biến khác) làm giá trị của nó. Nó cho phép lưu trữ địa chỉ của 1 số đối tượng khác để sử dụng sau này.

Giống như kiểu tham chiếu được khai báo bằng ký tự dấu và (&), kiểu con trỏ được khai báo bằng dấu hoa thị (*):

    int;  // a normal int
    int&; // an lvalue reference to an int value

    int*; // a pointer to an int value (holds the address of an integer value)

Cách sử dụng:

    int*:

    Được sử dụng để truy cập và thay đổi giá trị của biến được trỏ đến thông qua địa chỉ bộ nhớ.
    Cần giải tham chiếu bằng * để lấy giá trị.
    Có thể gán địa chỉ của các biến khác nhau cho cùng một con trỏ.

    int&:

    Được sử dụng để truy cập và thay đổi giá trị của biến được tham chiếu trực tiếp.
    Không cần giải tham chiếu.
    Luôn tham chiếu đến một biến cụ thể, không thể thay đổi để tham chiếu biến khác.

4. Pointer initialization

int main()
{

    int x{ 5 };

    int* ptr;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &x }; // a pointer initialized with the address of variable x

    return 0;

}

Giống như kiểu của một tham chiếu phải khớp với kiểu của đối tượng được trỏ tới, kiểu của con trỏ phải khớp với kiểu của đối tượng được trỏ tới:

int main()
{

    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double object
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int object

    return 0;

}

5. Pointers and assignment

Có thể sử dụng phép gán với con trỏ theo hai cách khác nhau:

    1. Thay đổi địa chỉ con trỏ đang trỏ tới

    #include <iostream>

    int main()
    {

    int x{ 5 };
    int* ptr{ &x }; // ptr initialized to point at x

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)

    int y{ 6 };
    ptr = &y; // // change ptr to point at y

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)

    return 0;
    }

    2. Thay đổi giá trị được trỏ tới

    #include <iostream>

    int main()

    {

    int x{ 5 };
    int* ptr{ &x }; // initialize ptr with address of variable x

    std::cout << x << '\n';    // print x's value
    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

    *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)

    std::cout << x << '\n';
    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

    return 0;
    }

Key insight:
    Khi chúng ta sử dụng một con trỏ không có tham chiếu (ptr), chúng ta đang truy cập vào địa chỉ được giữ bởi con trỏ. Việc sửa đổi điều này (ptr = &y) sẽ thay đổi nội dung con trỏ đang trỏ tới.

    Khi chúng ta tham chiếu một con trỏ (*ptr), chúng ta đang truy cập vào đối tượng được trỏ tới. Việc sửa đổi điều này (*ptr = 6;) sẽ thay đổi giá trị của đối tượng được trỏ tới.

6. Pointers behave much like lvalue references

Con trỏ và tham chiếu lvalue hoạt động tương tự nhau:
#include <iostream>

int main()
{

    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    return 0;

}

1 vài điểm khác nhau đáng chú ý:
    Tham chiếu phải được khởi tạo, con trỏ không yêu cầu khởi tạo

    Tài liệu tham khảo không phải là đối tượng, con trỏ là 1 đối tượng

    Tham chiếu không thể đổi đối tượng trỏ đến, con trỏ có thể đổi 

    Tham chiếu phải luôn liên kết với đối tượng, con trỏ có thể trỏ tới nothing

    Dùng tham chiếu khá an toàn, con trỏ khá nguy hiểm khi sử dụng

7. The address-of operator returns a pointer

8. The size of pointers

Kích thước của con trỏ phụ thuộc vào kiến ​​trúc mà tệp thực thi được biên dịch -- tệp thực thi 32 bit sử dụng địa chỉ bộ nhớ 32 bit -- do đó, con trỏ trên máy 32 bit là 32 bit (4 byte). Với tệp thực thi 64 bit, con trỏ sẽ có kích thước 64 bit (8 byte)

#include <iostream>

int main() // assume a 32-bit application
{

    char* chPtr{};        // chars are 1 byte
    int* iPtr{};          // ints are usually 4 bytes
    long double* ldPtr{}; // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n';  // prints 4
    std::cout << sizeof(ldPtr) << '\n'; // prints 4

    return 0;

}

9. Dangling pointers

Giống như một tham chiếu lơ lửng, một con trỏ lơ lửng là một con trỏ đang giữ địa chỉ của một đối tượng không còn hợp lệ

Giải tham chiếu cho 1 con trỏ bị treo dẫn đến những hành vi không xác định, vì bạn đang cố truy cập một đối tượng không còn hợp lệ.
ví dụ của dangling pointer:

#include <iostream>

int main()
{

    int x{ 5 };
    int* ptr{ &x };

    std::cout << *ptr << '\n'; // valid

    {
        int y{ 6 };
        ptr = &y;

        std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer

    return 0;
    
}

key insight
    giải tham chiếu một con trỏ không hợp lệ sẽ dẫn đến hành vi không xác định (undefined behavior)
    Bất kỳ cách sử dụng nào khác của một giá trị con trỏ không hợp lệ được xác định theo cách triển khai (implementation-defined): Điều này có nghĩa là hành vi của chương trình phụ thuộc vào trình biên dịch (compiler) và nền tảng cụ thể đang được sử dụng. Trình biên dịch có thể đưa ra các cảnh báo hoặc lỗi, nhưng cũng có thể cho phép chương trình chạy mà không thông báo gì. Tuy nhiên, kết quả vẫn là không mong muốn và có thể không ổn định.