[Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)

 (reference) tham chiếu hoạt động như một "biệt danh" hoặc "phím tắt" để truy cập trực tiếp vào một đối tượng trong bộ nhớ.

 1. Lvalue reference types

 lvalue reference (thường chỉ được gọi là tham chiếu vì trước C++ 11 chỉ có một loại tham chiếu) hoạt động như bí danh cho một giá trị hiện có (chẳng hạn như biến)

 Để khai báo kiểu tham chiếu lvalue, chúng ta sử dụng ký hiệu (&) trong khai báo kiểu

 ví dụ:

int      // a normal int type
int&     // an lvalue reference to an int object
double&  // an lvalue reference to a double object

2. Lvalue reference variables

Một trong những điều chúng ta có thể làm với loại tham chiếu lvalue là tạo biến tham chiếu lvalue. Biến tham chiếu lvalue là một biến đóng vai trò tham chiếu đến một giá trị lvalue (như những biến thông thường).

#include <iostream>

int main()
{
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    return 0;
}

BEST practice
Khi xác định một tham chiếu, hãy đặt ký hiệu bên cạnh loại (không phải tên của biến tham chiếu).

3. Modifying values through an lvalue reference

Chúng ta cũng có thể sử dụng tham chiếu để sửa đổi giá trị của đối tượng được tham chiếu:

ví dụ:

#include <iostream>

int main()
{
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    return 0;
}

Trong ví dụ trên, ref là bí danh của x, vì vậy chúng ta có thể thay đổi giá trị của x thông qua x hoặc ref.

4. Initialization of lvalue references

int main()
{
    int& invalidRef;   // error: references must be initialized

    int x { 5 };
    int& ref { x }; // okay: reference to int is bound to int variable

    return 0;
}

Khi một tham chiếu được khởi tạo với một đối tượng (hoặc hàm), chúng ta nói rằng nó được liên kết với đối tượng (hoặc hàm đó). Quá trình liên kết một tham chiếu như vậy được gọi là liên kết tham chiếu. Đối tượng (hoặc hàm) được tham chiếu đôi khi được gọi là referent.

5. References can’t be reseated (changed to refer to another object)

Sau khi được khởi tạo, một tham chiếu trong C++ không thể được đặt lại, nghĩa là nó không thể thay đổi để tham chiếu đến một đối tượng khác.

#include <iostream>

int main()
{
    int x { 5 };
    int y { 6 };

    int& ref { x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5

    return 0;
}

Khi một tham chiếu được đánh giá trong một biểu thức, nó sẽ phân giải thành đối tượng mà nó đang tham chiếu. Vì vậy, ref = y không thay đổi ref thành tham chiếu y. Đúng hơn, vì ref là bí danh của x nên biểu thức sẽ đánh giá như thể nó được viết x = y -- và vì y có giá trị là 6 nên x được gán giá trị 6.

6. Lvalue reference scope and duration

các biến tham chiếu tuân theo cùng các quy tắc về phạm vi và thời lượng mà các biến thông thường thực hiện:

7. References and referents have independent lifetimes

Thời gian tồn tại của một tham chiếu và thời gian tồn tại của tham chiếu của nó (referent) là độc lập. Nói cách khác, cả hai điều sau đây đều đúng: 
Một tham chiếu có thể bị hủy trước đối tượng mà nó đang tham chiếu. 
Đối tượng đang được tham chiếu có thể bị hủy trước khi tham chiếu.

#include <iostream>

void example1() {
  // Khai báo biến `x` toàn cục
  int x = 10;

  // Khai báo tham chiếu `ref` cục bộ trong hàm, trỏ đến `x`
  int& ref = x;

  // In giá trị của `x` qua tham chiếu
  std::cout << "Giá trị của x: " << ref << std::endl;
}

int main() {
  example1(); // Gọi hàm `example1`

  // Sau khi hàm kết thúc, tham chiếu `ref` bị hủy nhưng biến `x` toàn cục vẫn tồn tại
  return 0;
}

Tóm lại:

Tham chiếu chỉ là một "biệt danh" trỏ đến một đối tượng. Tuổi thọ của chúng không phụ thuộc lẫn nhau.
Điều quan trọng là phải đảm bảo đối tượng được tham chiếu vẫn tồn tại khi bạn sử dụng tham chiếu để tránh lỗi truy cập vùng nhớ đã giải phóng.

8. Dangling references

Khi một đối tượng đang được tham chiếu bị hủy trước khi tham chiếu đến nó, tham chiếu còn lại sẽ tham chiếu đến một đối tượng không còn tồn tại. Một tham chiếu như vậy được gọi là một tham chiếu treo (Dangling references).

9. References aren’t objects

Có lẽ đáng ngạc nhiên là references không phải là đối tượng trong C++. references không bắt buộc phải tồn tại hoặc chiếm dụng bộ nhớ. Nếu có thể, trình biên dịch sẽ tối ưu hóa các references bằng cách thay thế tất cả các lần xuất hiện của references bằng đối tượng được tham chiếu(referent). Tuy nhiên, điều này không phải lúc nào cũng có thể thực hiện được và trong những trường hợp như vậy, tài liệu tham khảo có thể yêu cầu lưu trữ.