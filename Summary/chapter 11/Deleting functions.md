[Deleting functions](https://www.learncpp.com/cpp-tutorial/deleting-functions/)

1. Deleting a function using the = delete specifier

Trong trường hợp có 1 hàm mà ta muốn nó không gọi được, có thể định nghĩa hàm đó đã bị xóa bằng cách sử dụng công cụ xác định = delete.

Nếu trình biên dịch khớp lệnh gọi hàm với hàm đã xóa, quá trình biên dịch sẽ bị dừng do lỗi biên dịch.

Ví dụ:

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(97);   // okay

    printInt('a');  // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match

    return 0;
}

Key insight

= delete có nghĩa là "t cấm nó" chứ không phải "nó không tồn tại".

Hàm đã xóa tham gia vào tất cả các giai đoạn chọn hàm xếp chồng (không chỉ trong giai đoạn khớp chính xác). Nếu chọn một hàm đã xóa thì sẽ xảy ra lỗi biên dịch.

2. Deleting all non-matching overloads

Việc xóa một loạt các hàm nạp chồng chức năng riêng lẻ có tác dụng tốt nhưng có thể dài dòng. Có thể đôi khi chúng ta muốn một hàm nhất định chỉ được gọi với các đối số có kiểu khớp chính xác với các tham số của hàm

Chúng ta có thể làm điều này bằng cách sử dụng một mẫu hàm(function template):


// This function will take precedence for arguments of type int(Hàm này sẽ được ưu tiên cho các đối số kiểu int)
void printInt(int x)
{
    std::cout << x << '\n';
}

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T>
void printInt(T x) = delete;

int main()
{
    printInt(97);   // okay
    printInt('a');  // compile error
    printInt(true); // compile error

    return 0;
}
