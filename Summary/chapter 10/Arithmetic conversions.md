[Arithmetic conversions](https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/)(Chuyển đổi số học)

Ví dụ int x{2 + 3};
Do 2 toán hạng 2 và 3 đều thuộc kiểu int, do đó 2 + 3 sẽ đánh giá kết quả 5 là int

Vậy nếu như y {2 + 3.5} ???

Trong trường hợp toán tử + đang được cấp một toán hạng kiểu int và một toán hạng khác kiểu double.

Trong C++, Một số toán tử nhất định yêu cầu các toán hạng phải cùng loại. Nếu 1 trong những toán tử này được triệu tập với 2 toán hạng khác loại, 1 hoặc cả hai sẽ ngầm được chuyển đổi để khớp nhau bằng cách sử dụng 1 số quy tắc gọi là usual arithmetic conversions.

1. The operators that require operands of the same type
The binary arithmetic operators: +, -, *, /, %
The binary relational operators: <, >, <=, >=, ==, !=
The binary bitwise arithmetic operators: &, ^, |
The conditional operator ?: (excluding the condition, which is expected to be of type bool)

2. The usual arithmetic conversion rules
long double (highest rank)
double
float
long long
long
int (lowest rank)
Các quy tắc sau được áp dụng để tìm loại phù hợp:

Nếu 1 toán hạng là kiểu số nguyên và còn lại là kiểu số thực, thì kiểu số nguyên sẽ chuyển thành kiểu số thực (không có Integral promotions)

Nếu thứ hạng của toán hạng không dấu lớn hơn thứ hạng của toán hạng có dấu thì toán hạng có dấu sẽ được chuyển thành loại toán hạng không dấu

Nếu loại toán hạng có dấu có thể đại diện cho tất cả các giá trị của loại toán hạng không dấu thì loại toán hạng không dấu được chuyển đổi thành loại toán hạng có dấu.

Ngược lại, toán hạng có thứ hạng thấp hơn sẽ được chuyển đổi thành loại toán hạng có thứ hạng cao hơn.

3. Signed and unsigned issues
Quy tắc chuyển đổi và phân cấp ưu tiên này có thể gây ra một số vấn đề khi trộn các giá trị có dấu và không dấu. Ví dụ: hãy xem đoạn mã sau:

#include <iostream>

int main() {
    unsigned int a = 42;
    int n = -60;

    // Chuyển đổi kiểu unsigned sang kiểu signed

    std::cout << "tong: " << a + n << std::endl;

    return 0;
}
Kết quả:
unsigned int 4294967291

Do quy tắc chuyển đổi, toán hạng int được chuyển đổi thành int không dấu. Và vì giá trị -18 nằm ngoài phạm vi của một unsigned int nên chúng ta nhận được kết quả mà chúng ta không mong đợi.


