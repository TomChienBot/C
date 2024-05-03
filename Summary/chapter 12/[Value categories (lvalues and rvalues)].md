[Value categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)

Trước khi nói về kiểu dữ liệu kết hợp đầu tiên(lvalue reference). Chúng ta sẽ đi đường vòng và tìm hiểu xem lvalue là gì.

Trong bài 1.10 - Giới thiệu về biểu thức, chúng ta đã định nghĩa một biểu thức là "sự kết hợp của các ký tự, biến, toán tử và lệnh gọi hàm có thể được thực thi để tạo ra một giá trị số ít".

ví dụ:

#include

int main()
{

    std::cout << 2 + 3 << '\n';

    return 0;

}

Ở chương trình trên biểu thức 2 + 3 được đánh giá để tạo giá trị 5.

chúng tôi cũng lưu ý rằng biểu thức có thể tạo ra tác dụng phụ tồn tại lâu hơn biểu thức:

#include <iostream>

int main()
{

    int x { 5 };
    ++x; // This expression statement has the side-effect of incrementing x
    std::cout << x << '\n'; // prints 6

    return 0;
}

Biểu thức ++x tăng giá trị của x, giá trị của x vẫn tiếp tục thay đổi cho dù biểu thức đã đánh giá xong (thay đổi vinh viễn giá trị của x) ở đây giá trị của x sẽ bằng 6 sau khi biểu thức được thực hiện chứ không quay về bằng 5.

2. The properties of an expression

Để giúp xác định cách đánh giá các biểu thức và nơi chúng có thể được sử dụng, tất cả các biểu thức trong C++ đều có hai thuộc tính:  a type and a value category.

3. The type of an expression (equivalent : tương đương)

Loại biểu thức tương đương với loại giá trị, đối tượng hoặc hàm sinh ra từ biểu thức được đánh giá

int main()
{

    auto v1 { 12 / 4 }; // int / int => int
    auto v2 { 12.0 / 4 }; // double / int => double

    return 0;
}

Đối với v1, trình biên dịch sẽ xác định (tại thời điểm biên dịch) rằng phép chia có hai toán hạng int sẽ tạo ra kết quả int, vì vậy int là loại biểu thức này

4. The value category of an expression

int main()
{

    int x{};

    x = 5; // valid: we can assign 5 to x
    5 = x; // error: can not assign value of x to literal value 5

    return 0;
}

Một trong những câu lệnh gán này là hợp lệ (gán giá trị 5 cho biến x) và một câu lệnh khác thì không (gán giá trị của x cho giá trị bằng chữ 5). Vậy làm thế nào trình biên dịch biết được biểu thức nào có thể xuất hiện hợp pháp ở hai bên của câu lệnh gán?

Câu trả lời nằm ở thuộc tính thứ hai của biểu thức: phạm trù giá trị. Loại giá trị của một biểu thức (hoặc biểu thức con) cho biết liệu một biểu thức có phân giải thành một giá trị, hàm hay một loại đối tượng nào đó hay không.

Trước C++11 chỉ có hai loại giá trị có thể có: lvalue và rvalue.

C++11, ba loại giá trị bổ sung (glvalue, prvalue và xvalue) đã được thêm vào để hỗ trợ một tính năng mới gọi là ngữ nghĩa di chuyển (move semantics).

5. Lvalue and rvalue expressions
Trong C++, lvalue (đọc là “ell-value”, viết tắt của “left value” hoặc “locator value”) là một biểu thức mà việc đánh giá của nó xác định danh tính của một đối tượng, bit-field hoặc hàm

Thuật ngữ "danh tính" được sử dụng theo tiêu chuẩn C++ nhưng không được xác định rõ ràng. Một thực thể (chẳng hạn như một đối tượng hoặc chức năng) có danh tính có thể được phân biệt với các thực thể tương tự khác (thường bằng cách so sánh địa chỉ của thực thể).

Các thực thể có danh tính có thể được truy cập thông qua mã định danh, tham chiếu hoặc con trỏ và thường có thời gian tồn tại lâu hơn một biểu thức hoặc câu lệnh

ví dụ:

int main()
{

    int x { 5 }; // 5 is an rvalue
    int y { x }; // x is an lvalue expression

    return 0;
}

Trong chương trình trên, biểu thức x là một biểu thức lvalue khi nó đánh giá biến x (có mã định danh).

lvalue có hai loại phụ: lvalue có thể sửa đổi là giá trị có giá trị có thể được sửa đổi. lvalue không thể sửa đổi là lvalue có giá trị không thể sửa đổi (vì giá trị là const hoặc constexpr)

ví dụ:

int main()
{

    int x{};
    const double d{};

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression

    return 0;
}

Trong C++, rvalue (đọc là “ar-value”, viết tắt của “right value”) là một loại biểu thức mà không có một địa chỉ cụ thể mà chương trình của bạn có thể truy cập1. Rvalue thường đại diện cho dữ liệu mà bạn không thể gán một giá trị mới cho nó, tức là bạn không thể đặt nó ở bên trái của một toán tử gán

Ví dụ:

int return5()
{

    return 5;
}

int main()
{

    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    return 0;
}

Key insight

Lvalue giống như nhãn mác chỉ vị trí lưu trữ của một thứ gì đó.
Rvalue là thứ thực sự được lưu trữ tại các vị trí đó

6. Lvalue to rvalue conversion

int main()
{

    int x { 5 };
    int y { x }; // x is an lvalue expression

    return 0;
}

các biểu thức lvalue sẽ ngầm chuyển đổi thành các biểu thức rvalue trong các bối cảnh trong đó rvalue được mong đợi nhưng lvalue được cung cấp

ví dụ:

int main()
{

    int x{ 1 };
    int y{ 2 };

    x = y; // y is a modifiable lvalue, not an rvalue, but this is legal

    return 0;
}

Trong trường hợp này, y là một biểu thức lvalue, nhưng nó trải qua một chuyển đổi lvalue-thành-rvalue, ước tính giá trị của y (2), sau đó được gán cho x.
