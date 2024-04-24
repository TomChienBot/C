[Implicit type conversion](https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/) (chuyển đổi loại ngầm định)

1. Introduction to type conversion
Giá trị của 1 đối tượng được lưu trữ dưới dạng 1 chuỗi bit. kiểu dữ liệu của đối tượng cho trình biên dịch biết cách thông dịch các bit đó thành các giá trị có ý nghĩa. 

các kiểu dữ liệu khác nhau có thể biểu diễn cùng một số một cách khác nhau. Ví dụ:
integer value 3 có thể lưu trữ dưới dạng nhị phân: 0000 0000 0000 0000 0000 0000 0000 0011
Trong khi float giá trị 3.0: 0100 0000 0100 0000 0000 0000 0000 0000.

Ví dụ 2:
float f{ 3 }; // initialize floating point variable with int 3

Trường hợp này, Trình biên dịch không thể chỉ copy bit biểu diễn kiểu int của giá trị 3 vào bộ nhớ được phân bổ cho float biến f. Nó cần chuyển đổi giá trị nguyên của 3 thành giá trih float tương đương 3.0. Cái có thể lưu trong bộ nhớ phân bổ cho f.

Quá trình tạo ra một giá trị mới thuộc loại nào đó từ một giá trị thuộc loại khác được gọi là chuyển đổi.(conversion)

key insight:
Chuyển đổi không thay đổi giá trị hoặc loại được chuyển đổi. Thay vào đó, một giá trị mới với loại mong muốn sẽ được tạo do chuyển đổi.

2. Implicit type conversion (Chuyển đổi kiểu ngầm định)
Implicit type conversion (hay còn gọi automatic type conversion or coercion)  được thực hiện tự động bởi trình biên dịch khi một loại dữ liệu được yêu cầu nhưng lại được cung cấp 1 loại dữ liệu khác.
Phần lớn chuyển đổi trong C++ là chuyển đổi ngầm định.
Ví dụ:
double d{ 3 }; // int value 3 implicitly converted to type double
d = 6; // int value 6 implicitly converted to type double

float doSomething()
{
    return 3.0; // double value 3.0 implicitly converted to type float
}

3. What happens when a type conversion is invoked

Nếu trình biên dịch không thể tìm thấy một chuyển đổi có thể chấp nhận được thì quá trình biên dịch sẽ thất bại kèm theo lỗi biên dịch. Chuyển đổi loại có thể thất bại vì bất kỳ lý do nào. Ví dụ, trình biên dịch có thể không biết cách chuyển đổi giá trị giữa kiểu gốc và kiểu mong muốn. Trong các trường hợp khác, câu lệnh có thể không cho phép một số loại chuyển đổi nhất định:
Ví dụ:
int x { 3.5 }; // brace-initialization disallows conversions that result in data loss

4. The standard conversions

Các chuyển đổi tiêu chuẩn có thể được chia thành 4 loại:
Numeric promotions 

Numeric conversions

Arithmetic conversions

Other conversions (which includes various pointer and reference conversions)

Khi cần chuyển đổi loại, trình biên dịch có thể áp dụng 0, một hoặc nhiều chuyển đổi tiêu chuẩn trong quá trình chuyển đổi.

As an aside…:
Làm cách nào để bạn có chuyển đổi loại không có chuyển đổi? Ví dụ: trên các kiến ​​trúc trong đó cả int và long đều có cùng kích thước và phạm vi, cùng một chuỗi bit được sử dụng để biểu thị các giá trị của cả hai loại. Do đó, không cần chuyển đổi thực tế để chuyển đổi giá trị giữa các loại đó -- giá trị có thể được sao chép một cách đơn giản.