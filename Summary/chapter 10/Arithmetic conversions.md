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


