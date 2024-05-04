[Pass by lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)

Bài học trước có thể bạn sẽ thắc mắc: Tại sao phải tạo alias(bí danh) cho 1 biến trong khi ta có thể sử dụng luôn biến đấy.

Trong bài này , ta sẽ tìm hiểu sâu hơn về tham chiếu (reference) hữu dụng ra sao.

ví dụ:

#include <iostream>

void printValue(int y)
{

    std::cout << y << '\n';

} // y is destroyed here

int main()
{

    int x { 2 };

    printValue(x); // x is passed by value (copied) into parameter y (inexpensive)

    return 0;

}

Ở chương trình trên, khi printValue(x) được gọi, giá trị x {2} được copy vào tham số y. Khi kết thúc hàm, y sẽ bị hủy

Có nghĩa là khi gọi 1 hàm, ta đã thực hiện copy giá trị của đối số, chỉ sử dụng trong thời gian ngắn và hủy nó. May mắn thay, vì các loại cơ bản dễ sao chép nên đây không phải là vấn đề.
1. Some objects are expensive to copy

Hầu hết các kiểu dữ liệu được cung cấp bởi thư viện tiêu chuẩn (như là std::string) là kiểu dữ liệu class. Class types thường khó để copy.

Chúng ta luôn tránh những copies không cần thiết, đặc biết là ta sẽ hủy đống copies gần như ngay lập tức.

#include <iostream>
#include <string>

void printValue(std::string y)
{

    std::cout << y << '\n';

} // y is destroyed here

int main()
{

    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)

    return 0;

}

Chương trình vẫn hoạt động như ta mong đợi nhưng nó không hiệu quả. 

ta có thể làm tốt hơn.

2. Pass by reference

1 cách tránh những bản copy "tốn kém" của đối số khi gọi hàm là sử dụng pass by reference thay vì pass by value.

Khi sử dụng pass by reference ta khai báo 1 tham số của hàm bằng kiểu tham chiếu(reference type hoặc const reference type) thay vì kiểu thông thường.

Khi hàm được gọi, từng tham số tham chiếu sẽ liên kết với những đối số thích hợp. Bởi vì tham chiếu hoạt động như 1 bí danh(alias) cho đối số nên ko có bản copy nào được tạo.

#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{

    std::cout << y << '\n';

} // y is destroyed here

int main()
{

    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;

}

Key insight:

Truyền theo tham chiếu cho phép chúng ta truyền các đối số cho một hàm mà không cần tạo bản sao của các đối số đó mỗi khi hàm được gọi.

3. Pass by reference allows us to change the value of an argument (truyền theo tham số cho phép ta thay đổi giá trị của đối số)

Khi pass by value, Tham số của hàm sẽ nhận bản copy cho nên bất kỳ thay đổi nào đối với bản sao này bên trong hàm sẽ không ảnh hưởng đến đối tượng gốc bên ngoài hàm:

#include <iostream>

void addOne(int y) // y is a copy of x
{

    ++y; // this modifies the copy of x, not the actual object x

}

int main()
{

    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;

}

Kết quả sẽ ra 5, 5 hàm addone chỉ thay đổi bản sao của x , không phải x.

#include <iostream>

void addOne(int& y) // y is bound to the actual object x
{

    ++y; // this modifies the actual object x

}

int main()
{

    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has been modified

    return 0;

}

Kết quả : 5, 6 hàm add one thay đổi giá trị thực sự của x.

Key insight
Truyền các giá trị bằng cách tham chiếu đến non-const cho phép chúng ta viết các hàm sửa đổi giá trị của các đối số được truyền vào.

4. Pass by reference can only accept modifiable lvalue arguments

tham chiếu non-const chỉ có thể liên kết để thay đổi giá trị của lvalue, điều này có nghĩa là truyền theo tham chiếu chỉ hoạt động với các đối số là giá trị có thể sửa đổi

#include <iostream>

void printValue(int& y) // y only accepts modifiable lvalues
{
    std::cout << y << '\n';
}

int main()
{

    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
    
}