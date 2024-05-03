[Lvalue references to const](https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/)

1. Lvalue reference to const(Tham chiếu giá trị tới const)
\Bằng cách sử dụng từ khóa const khi khai báo một tham chiếu lvalue, chúng ta nói với một tham chiếu lvalue để coi đối tượng mà nó đang tham chiếu là const

Tham chiếu giá trị tới const có thể liên kết với các giá trị không thể sửa đổi

Ví dụ

int main()

{

    const int x { 5 };    // x is a non-modifiable lvalue
    
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value

    return 0;
}

Bởi vì các tham chiếu giá trị tới const coi đối tượng mà chúng đang tham chiếu là const, nên chúng có thể được sử dụng để truy cập nhưng không sửa đổi giá trị được tham chiếu

ví dụ:


int main()
{

    const int x { 5 };    // x is a non-modifiable lvalue
    
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value

    std::cout << ref << '\n'; // okay: we can access the const object
    ref = 6;                  // error: we can not modify an object through a const reference

    return 0;
}

2. Initializing an lvalue reference to const with a modifiable lvalue

Tham chiếu giá trị tới const cũng có thể liên kết với các giá trị có thể sửa đổi. Trong trường hợp như vậy, đối tượng được tham chiếu được coi là const khi được truy cập thông qua tham chiếu (mặc dù đối tượng cơ bản không phải là const):

#include <iostream>

int main()
{

    int x { 5 };          // x is a modifiable lvalue
    
    const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n'; // okay: we can access the object through our const reference
    ref = 7;                  // error: we can not modify an object through a const reference

    x = 6;                // okay: x is a modifiable lvalue, we can still modify it through the original identifier

    return 0;
}

Best practice:

Ưu tiên các tham chiếu giá trị lvalue đến const thay vì tham chiếu lvalue đến không phải const trừ khi bạn cần sửa đổi đối tượng đang được tham chiếu.

3. Initializing an lvalue reference to const with an rvalue

Các tham chiếu lvalue đến const cũng có thể liên kết với các rvalue:

#include <iostream>

int main()

{

    const int& ref { 5 }; // okay: 5 is an rvalue

    std::cout << ref << '\n'; // prints 5

    return 0;
}

4. Initializing an lvalue reference to const with a value of a different type

Các tham chiếu giá trị tới const thậm chí có thể liên kết với các giá trị thuộc loại khác, miễn là các giá trị đó có thể được chuyển đổi ngầm thành loại tham chiếu:

#include <iostream>

int main()
{

    // case 1
    
    const double& r1 { 5 };  // temporary double initialized with value 5, r1 binds to temporary

    std::cout << r1 << '\n'; // prints 5

    // case 2
    char c { 'a' };
    const int& r2 { c };     // temporary int initialized with value 'a', r2 binds to temporary

    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)

    return 0;
}

Một đối tượng double tạm thời được tạo và khởi tạo với giá trị 5.
Tham chiếu r1 được liên kết (gán) với đối tượng tạm thời này.
Do r1 là tham chiếu const, nó không thể thay đổi giá trị của đối tượng tạm thời.
Khi dấu chấm phẩy (;) được sử dụng, đối tượng tạm thời bị hủy. Tuy nhiên, r1 vẫn giữ tham chiếu đến vị trí bộ nhớ nơi đối tượng tạm thời tồn tại, mặc dù giá trị không còn hợp lệ. Lý do là vì bản thân tham chiếu không bị hủy.

Trường hợp 2, đối tượng tạm thời kiểu int được khởi tạo với giá trị char a. Sau đó const int& r2 được liên kết với đối tượng int tạm thời này.

Cả hai trường hợp, kiểu dữ liệu của reference và biến tạm thời trùng nhau.

5. Const references bound to temporary objects extend the lifetime of the temporary object

Các đối tượng tạm thời thường bị hủy ở cuối biểu thức mà chúng được tạo.

Tuy nhiên, hãy xem xét điều gì sẽ xảy ra trong ví dụ trên nếu đối tượng tạm thời được tạo để giữ rvalue 5 bị hủy ở cuối biểu thức khởi tạo ref. Tham chiếu tham chiếu sẽ bị treo lơ lửng (tham chiếu đến một đối tượng đã bị phá hủy) và chúng tôi sẽ nhận được hành vi không xác định khi cố gắng truy cập tham chiếu tham chiếu.

Để tránh các tham chiếu lơ lửng trong những trường hợp như vậy, C++ có một quy tắc đặc biệt: Khi tham chiếu giá trị const được liên kết trực tiếp với một đối tượng tạm thời, thời gian tồn tại của đối tượng tạm thời được kéo dài để phù hợp với thời gian tồn tại của tham chiếu.

#include <iostream>

int main()

{

    const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref << '\n'; // Therefore, we can safely use it here

    return 0;
    
} // Both ref and the temporary object die here

Key insight:

Tham chiếu giá trị chỉ có thể liên kết với các giá trị có thể sửa đổi

Tham chiếu giá trị đến const có thể liên kết với các giá trị có thể sửa đổi, giá trị không thể sửa đổi và rvalue. Điều này làm cho chúng trở thành một loại tài liệu tham khảo linh hoạt hơn nhiều.
