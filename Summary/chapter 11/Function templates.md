[Function templates](https://www.learncpp.com/cpp-tutorial/function-templates/)

1. Introduction to C++ templates

Thay vì tạo thủ công một loạt các hàm hoặc lớp gần như giống hệt nhau(mỗi hàm cho 1 kiểu dữ liệu khác nhau), thay vào đó chúng ta sẽ tạo 1 template. 

Không giống như định nghĩa thông thường (trong đó tất cả các loại phải được chỉ định), trong một mẫu, chúng ta có thể sử dụng một hoặc nhiều placeholder types. placeholder type đại diện cho một số loại chưa được biết tại thời điểm template được viết nhưng sẽ được cung cấp sau.

placeholder type là một loại đặc biệt của kiểu dữ liệu mà không được chỉ định cụ thể khi khai báo biến hoặc hàm. Thay vào đó, kiểu dữ liệu sẽ được trình biên dịch tự động suy luận dựa trên ngữ cảnh sử dụng. Điều này thường được thực hiện thông qua từ khóa auto hoặc decltype.

ví dụ:

auto x = 5; // x có kiểu int vì 5 là một literal số nguyên
auto y = 3.14; // y có kiểu double vì 3.14 là một literal số thực

trong ví dụ trên thì auto là 1 placeholder type

Khi một template được xác định, trình biên dịch có thể sử dụng template đó để tạo ra bao nhiêu hàm (hoặc lớp) xếp chồng nếu cần, mỗi hàm sử dụng các kiểu thực tế khác nhau!

key insight
Trình biên dịch có thể sử dụng một template duy nhất để tạo ra một họ các hàm hoặc lớp liên quan, mỗi lớp sử dụng một tập hợp các loại khác nhau.

2. Function templates

Mẫu hàm(function template) là  là một công cụ mạnh mẽ cho phép bạn viết các chương trình tổng quát có thể làm việc với nhiều kiểu dữ liệu khác nhau. Mẫu hàm giúp bạn tạo ra một hàm duy nhất mà có thể được sử dụng cho các kiểu dữ liệu khác nhau mà không cần viết lại mã nguồn cho mỗi kiểu

3. Creating a templated max function

int max(int x, int y)
{
    return (x < y) ? y : x;
}

Để tạo một mẫu hàm, chúng ta sẽ thực hiện hai việc. Đầu tiên, chúng ta sẽ thay thế các type cụ thể của hàm bằng các type template parameter. Ở đây, chỉ có 1 kiểu int cần thay thế nên chỉ cần 1 loại type template parameter(cái gọi là T)

T max(T x, T y) // won't compile because we haven't defined T
{
    return (x < y) ? y : x;
}

Hàm sẽ ko đc biên dịch vì trình biên dịch chẳng biết T là cái gì! và nó vẫn là 1 hàm bình thường chứ không phải là function template 
Tiếp theo, chúng ta sẽ nói với trình biên dịch rằng đây là một function template và T là type template parameter là 1 placeholder cho bất kỳ loại nào

Điều này được thực hiện bằng cách sử dụng cái được gọi là  template parameter declaration.

template <typename T> // this is the template parameter declaration
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

4. Naming template parameters