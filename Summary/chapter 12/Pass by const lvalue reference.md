[Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)

Không giống tham chiếu tới non-const( Chỉ có thể liên kết với lvalue có thể thay đổi), tham chiếu tới const có thể liên kết với lvalue có thể sửa đổi, lvalue không thể sửa đổi và rvalue. Do đó , Nếu tạo một tham số tham chiếu const thì nó sẽ có thể liên kết với bất kỳ loại đối số nào

Ví dụ:

#include <iostream>

void printRef(const int& y) // y is a const reference
{

    std::cout << y << '\n';

}

int main()
{

    int x { 5 };
    printRef(x);   // ok: x is a modifiable lvalue, y binds to x

    const int z { 5 };
    printRef(z);   // ok: z is a non-modifiable lvalue, y binds to z

    printRef(5);   // ok: 5 is rvalue literal, y binds to temporary int object

    return 0;

}

Truyền tham chiếu const mang lại lợi ích chính giống như truyền bằng tham chiếu (tránh tạo bản sao của đối số), đồng thời đảm bảo rằng hàm không thể thay đổi giá trị được tham chiếu

Best practice

Ưu tiên truyền tham chiếu const hơn là tham chiếu non-const trừ khi bạn có lí do để làm khác( Ví dụ: Hàm cần thay đổi giá trị của đối số ).

1. Passing values of a different type to a const lvalue reference parameter

Tham chiếu const lvalue có thể liên kết với giá trị của nhiều loại(type), miễn là giá trị đó có thể chuyển đổi thành kiểu tham chiếu.

Ta có thể chuyển một giá trị làm đối số cho tham số  hoặc tham số tham chiếu const theo cùng một cách

#include <iostream>

void printVal(double d)
{

    std::cout << d << '\n';

}

void printRef(const double& d)
{

    std::cout << d << '\n';

}

int main()
{

    printVal(5); // 5 converted to temporary double, copied to parameter d
    printRef(5); // 5 converted to temporary double, bound to parameter d

    return 0;

}

2. Mixing pass by value and pass by reference (Kết hợp truyền giá trị và truyền tham số)

Một hàm có nhiều tham số có thể xác định xem mỗi tham số được truyền theo giá trị hay được truyền theo tham chiếu riêng lẻ

#include <string>

void foo(int a, int& b, const std::string& c)
{
}

int main()
{

    int x { 5 };
    const std::string s { "Hello, world!" };

    foo(5, x, s);

    return 0;

}

3. When to pass by (const) reference

Kiểu lớp (class) thường tốn nhiều bộ nhớ để sao chép: Khi bạn truyền một đối tượng kiểu lớp theo giá trị, toàn bộ đối tượng đó sẽ được sao chép sang một vùng nhớ mới bên trong hàm. Đối với các đối tượng nhỏ, việc sao chép này có thể không đáng kể. Nhưng đối với các đối tượng lớn, chứa nhiều dữ liệu phức tạp, việc sao chép này có thể tốn nhiều thời gian và tài nguyên.
Truyền tham chiếu const chỉ sao chép địa chỉ: Khi bạn truyền một đối tượng kiểu lớp bằng tham chiếu const, bạn chỉ cần sao chép địa chỉ của đối tượng đó. Điều này giống như đưa cho hàm "bản đồ" đến vị trí của đối tượng thay vì sao chép toàn bộ đối tượng. Hàm có thể truy cập và sử dụng giá trị của đối tượng gốc mà không cần phải sao chép nó.
const đảm bảo tính an toàn: Việc sử dụng tham chiếu const đảm bảo rằng hàm không thể thay đổi giá trị của đối tượng gốc một cách vô tình. Điều này giúp tránh các lỗi ngoài ý muốn và cải thiện tính an toàn của code.

Ví dụ: có một class Point để biểu diễn một điểm trong không gian 2D:

class Point {

public:
    int x, y;

}

Nếu muốn truyền đến một hàm tính toán khoảng cách, nên sử dụng tham chiếu const:

void calculateDistance(const Point& p1, const Point& p2) {

  // ... tính toán khoảng cách dựa trên p1.x, p1.y, p2.x, p2.y

}

Bằng cách này, hàm calculateDistance chỉ cần địa chỉ của các đối tượng Point, tránh việc sao chép toàn bộ dữ liệu của chúng.

4. The cost of pass by value vs pass by reference

Không phải tất cả kiểu class cần truyền bằng tham số.  Và câu hỏi là tại sao chúng ta không truyền mọi thứ bằng tham chiếu ??

Có hai điểm chính sẽ giúp chúng ta hiểu khi nào nên chuyển theo giá trị so với chuyển theo tham chiếu:
 
Đối với những đối tượng có thể sao chép dễ dàng(không tốn nhiều tài nguyên), chi phí sao chép tương tự như chi phí liên kết, vì vậy chúng tôi ưu tiên truyền giá trị để mã được tạo sẽ nhanh hơn.

Đối với các đối tượng sao chép tốn kém(tốn nhiều tài nguyên), chi phí sao chép chiếm ưu thế, vì vậy chúng tôi ưu tiên chuyển qua tham chiếu (const) để tránh tạo bản sao.

Best practice:

Ưu tiên chuyển theo giá trị cho các đối tượng có chi phí sao chép rẻ và chuyển theo tham chiếu const cho các đối tượng có chi phí sao chép đắt. Nếu bạn không chắc chắn liệu một đối tượng có giá rẻ hay đắt để sao chép, hãy ưu tiên chuyển qua tham chiếu const.

5. For function parameters, prefer std::string_view over const std::string& in most cases 

Một câu hỏi thường xuất hiện trong C++ hiện đại: khi viết một hàm có tham số chuỗi, loại tham số nên là const std::string& hay std::string_view?

Trong hầu hết trường hợp, std::string_view là sự lựa chọn tốt hơn vì nó có thể xử lý nhiều loại đối số một cách hiệu quả.

    void doSomething(const std::string&);
    void doSomething(std::string_view);   // prefer this in most cases

Best practice:

Ưu tiên truyền chuỗi bằng cách sử dụng std::string_view (theo giá trị) thay vì const std::string&, trừ khi hàm của bạn gọi các hàm khác yêu cầu chuỗi kiểu C hoặc tham số std::string.

