[Assert and static_assert](https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/)

void printDivision(int x, int y)
{
    if (y != 0)
        std::cout << static_cast<double>(x) / y;
    else
        std::cerr << "Error: Could not divide by zero\n";
}

1. Preconditions, invariants, and postconditions
Trong lập trình, điều kiện tiên quyết là bất kỳ điều kiện nào phải đúng trước khi thực thi một số phần mã (thường là phần thân của hàm). Trong ví dụ trước, chúng tôi kiểm tra rằng y != 0 là điều kiện tiên quyết nhằm đảm bảo y có giá trị khác 0 trước khi chia cho y.

Tốt nhất nên đặt các điều kiện tiên quyết cho một hàm ở đầu hàm, sử dụng tính năng quay lại sớm để quay lại cho người gọi nếu điều kiện tiên quyết không được đáp ứng

(invariants) Bất biến là một điều kiện phải đúng trong khi một phần mã nào đó đang thực thi. Điều này thường được sử dụng với các vòng lặp, trong đó phần thân vòng lặp sẽ chỉ thực thi miễn là bất biến là đúng.

(postconditions) hậu điều kiện là điều gì đó phải đúng sau khi thực thi một phần mã nào đó. Hàm của chúng ta không có bất kỳ điều kiện nào.

2. Assertions (Khẳng định)
Assertions là một biểu thức sẽ đúng trừ khi có lỗi trong chương trình. Nếu biểu thức đánh giá là đúng thì câu lệnh khẳng định sẽ không làm gì cả. Nếu biểu thức điều kiện được đánh giá là sai, một thông báo lỗi sẽ hiển thị và chương trình sẽ bị chấm dứt (thông qua std::abort)

Khi một xác nhận được đánh giá là sai, chương trình của bạn sẽ bị dừng ngay lập tức. Điều này mang lại cho bạn cơ hội sử dụng các công cụ gỡ lỗi để kiểm tra trạng thái chương trình của bạn và xác định lý do tại sao xác nhận không thành công. Làm ngược lại, bạn có thể tìm và khắc phục sự cố.
Nếu không có xác nhận để phát hiện lỗi và thất bại, lỗi như vậy có thể khiến chương trình của bạn gặp trục trặc sau này. Trong những trường hợp như vậy, có thể rất khó để xác định mọi thứ đang sai ở đâu hoặc nguyên nhân cốt lõi của vấn đề thực sự là gì.
Trong C++, các xác nhận thời gian chạy được triển khai thông qua macro tiền xử lý khẳng định, nằm trong tiêu đề <cassert>.
#include <cassert> // for assert()

Mặc dù các xác nhận thường được sử dụng nhiều nhất để xác thực các tham số hàm, nhưng chúng có thể được sử dụng ở bất cứ đâu bạn muốn xác thực rằng điều gì đó là đúng.

3. Making your assert statements more descriptive

assert(found);// this  assertion isn't very descriptive.

Nếu xác nhận này được kích hoạt, xác nhận sẽ nói:

Assertion failed: found, file C:\\VCProjects\\Test.cpp, line 34

Rõ ràng Found là found đã false (từ khi assert kích hoạt) nhưng là cái found nào ? , phải quay lại xem code để tìm nó.

Có một số trick như sau:

assert(found && "Car could not be found in database");

Một chuỗi ký tự luôn đánh giá là Boolean true. Vì vậy, found is false, false && true is false. If found is true, true && true is true. Do đó, việc AND logic một chuỗi ký tự không ảnh hưởng đến việc đánh giá khẳng định.

4. Asserts vs error handling
5. static_assert 
C++ cũng có một loại khẳng định khác gọi là static_assert

Static_assert là một xác nhận được kiểm tra tại thời điểm biên dịch thay vì trong thời gian chạy, với static_assert bị lỗi gây ra lỗi biên dịch. Không giống như assert, được khai báo trong tiêu đề <cassert>, static_assert là một từ khóa, do đó không cần đưa vào header để sử dụng nó.
ví dụ:

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

int main()
{
	return 0;
}

1>c:\consoleapplication1\main.cpp(19): error C2338: long must be 8 bytes

1 vài chú ý với static_assert:
Vì static_assert được trình biên dịch đánh giá nên điều kiện phải là biểu thức không đổi
static_assert có thể được đặt ở bất kỳ đâu trong tệp mã (ngay cả trong không gian tên chung).


