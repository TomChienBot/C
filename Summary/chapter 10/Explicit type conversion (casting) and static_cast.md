[Explicit type conversion (casting) and static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)

1. Type casting
    C++ hỗ trợ 5 loại ép kiểu khác nhau:  C-style casts, static casts, const casts, dynamic casts, and reinterpret casts.

2. C-style casts
{
    int x { 10 };
    int y { 4 };


    double d { (double)x / y }; // convert x to a double so we get floating point division
    std::cout << d << '\n'; // prints 2.5

    return 0;
}
Sử dụng C-style cast để yêu cầu trình biên dịch chuyển đổi x thành dạng double. Bởi vì toán hạng bên trái chuyển thành dạng thập phân nên toán hạng bên phải cũng sẽ chuyển thành thập phân. Phép chia sẽ được thực hiện dưới dạng thập phân thay vì chia dưới dạng nguyên.

BEST PRACTICE:
TRÁNH SỬ DỤNG C-STYPLE CASTS.

3. static_cast

C++ giới thiệu một toán tử ép kiểu có tên là static_cast, có thể được sử dụng để chuyển đổi giá trị của một kiểu thành giá trị của kiểu khác.

int main()
{
    char c { 'a' };
    std::cout << c << ' ' << static_cast<int>(c) << '\n'; // prints a 97

    return 0;
}

Toán tử static_cast lấy một biểu thức làm đầu vào và trả về giá trị được chuyển đổi thành loại được chỉ định bên trong dấu ngoặc nhọn.

Ưu điểm chính của static_cast là nó cung cấp khả năng kiểm tra kiểu thời gian biên dịch, khiến việc mắc lỗi vô ý trở nên khó khăn hơn.

// a C-style string literal can't be converted to an int, so the following is an invalid conversion
int x { static_cast<int>("Hello") }; // invalid: will produce compilation error

static_cast cũng kém mạnh hơn so với c-style cast, do đó bạn không thể vô tình xóa const hoặc làm những việc khác mà bạn có thể không có ý định làm.

BEST PRACTICE:
Ưu tiên static_cast khi bạn cần chuyển đổi một giá trị từ loại này sang loại khác.

4. Using static_cast to make narrowing conversions explicit
Trình biên dịch thường sẽ đưa ra cảnh báo khi thực hiện chuyển đổi loại ngầm định có khả năng không an toàn (thu hẹp). 
Ví dụ:

int i { 48 };
char ch = i; // implicit narrowing conversion

Để giải quyết vấn đề này:

int i { 48 };

// explicit conversion from int to char, so that a char is assigned to variable ch
char ch { static_cast<char>(i) };
