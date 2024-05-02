[Function template instantiation](https://www.learncpp.com/cpp-tutorial/function-template-instantiation/)

1. Using a function template

Function templates không thực sự là 1 hàm. mã code function template ko trực tiếp được biên dịch. Thay vào đó, function templates chỉ có 1 nhiệm vụ duy nhất: tạo hàm (thứ được biên dịch và thực thi)

Ví dụ:

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}

Khi trình biên dịch gặp lệnh gọi hàm max<int>(1, 2), nó sẽ xác định rằng định nghĩa hàm cho max<int>(int, int) chưa tồn tại. Do đó, trình biên dịch sẽ ngầm sử dụng mẫu hàm max<T> của chúng tôi để tạo một mẫu.

Quá trình tạo hàm (với các kiểu cụ thể) từ các mẫu hàm (với các kiểu mẫu) được gọi là khởi tạo hàm mẫu

2. Template argument deduction

std::cout << max<int>(1, 2) << '\n'; // specifying we want to call max<int>

Trong trường hợp này ta muốn gọi hàm max với kiểu int(Thay thế T = int), nhưng đồng thời cũng truyền đối số với kiểu int vào hàm.

Trong trường hợp này chúng ta không cần chỉ định loại thực tế -- thay vào đó, chúng ta có thể sử dụng template argument đeuction ( suy luận đối số mẫu) để trình biên dịch suy ra loại thực tế sẽ được sử dụng từ các loại đối số trong lệnh gọi hàm.

ví dụ:

std::cout << max<>(1, 2) << '\n';
std::cout << max(1, 2) << '\n';

Trong ví dụ này, trình biên dịch sẽ suy ra rằng việc sử dụng hàm mẫu max<T> với kiểu thực tế int cho phép nó khởi tạo hàm max<int>(int, int) trong đó kiểu của cả hai tham số mẫu (int) khớp với kiểu được cung cấp đối số (int).

Sự khác biệt giữa hai trường hợp liên quan đến cách trình biên dịch giải quyết lệnh gọi hàm từ một tập hợp các hàm bị quá tải. Trong trường hợp trên cùng (với dấu ngoặc nhọn trống), trình biên dịch sẽ chỉ xem xét tình trạng quá tải của hàm mẫu max<int> khi xác định hàm quá tải nào sẽ được gọi. Trong trường hợp dưới cùng (không có dấu ngoặc nhọn), trình biên dịch sẽ xem xét cả tình trạng quá tải của hàm mẫu max<int> và tình trạng quá tải của hàm không phải mẫu tối đa.

BEST PRACTICE

Ưu tiên cú pháp gọi hàm thông thường khi thực hiện lệnh gọi đến một hàm được khởi tạo từ một mẫu hàm (trừ khi bạn cần phiên bản mẫu hàm được ưu tiên hơn một hàm không phải mẫu phù hợp).

3. Function templates with non-template parameters

Có thể tạo các mẫu hàm có cả tham số mẫu và tham số không phải mẫu

Các tham số mẫu loại có thể được khớp với bất kỳ loại nào và các tham số không phải mẫu hoạt động giống như các tham số của các hàm thông thường.

Ví dụ:

// T is a type template parameter
// double is a non-template parameter
// We don't need to provide names for these parameters since they aren't used
template <typename T>
int someFcn (T, double)
{
    return 5;
}

int main()
{
    someFcn(1, 3.4); // matches someFcn(int, double)
    someFcn(1, 3.4f); // matches someFcn(int, double) -- the float is promoted to a double
    someFcn(1.2, 3.4); // matches someFcn(double, double)
    someFcn(1.2f, 3.4); // matches someFcn(float, double)
    someFcn(1.2f, 3.4f); // matches someFcn(float, double) -- the float is promoted to a double

    return 0;
}

4. Instantiated functions may not always compile

#include <iostream>
#include <string>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::string hello { "Hello, world!" };
    std::cout << addOne(hello) << '\n';

    return 0;
}

Khi trình biên dịch cố gắng giải quyết addOne(hello) nó sẽ không tìm thấy hàm bình thường (non- template) khớp với addOne(std::string). Nhưng nó sẽ tìm mẫu hàm (function template) của chúng ta cho addOne(T) và xác định rằng nó có thể tạo ra hàm addOne(std::string) từ nó Vì vậy, trình biên dịch sẽ tạo và biên dịch phần này:

#include <iostream>
#include <string>

template <typename T>
T addOne(T x);

template<>
std::string addOne<std::string>(std::string x)
{
    return x + 1;
}

int main()
{
    std::string hello{ "Hello, world!" };
    std::cout << addOne(hello) << '\n';

    return 0;
}

Tuy nhiên, nó sẽ gặp lỗi, bởi x + 1 không có ý nghĩa gì khi x là std::string.

5. Using function templates in multiple files

main.cpp:
#include <iostream>

template <typename T>
T addOne(T x); // function template forward declaration

int main()
{
    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    return 0;
}

add.cpp:

template <typename T>
T addOne(T x) // function template definition
{
    return x + 1;
}

Nếu addone là non-template function, chương trình sẽ hoạt động ngon lành.

Nếu addone là 1 template, trương trình sẽ không hoạt động.

Cách xử lí nhanh gọn nhất là đưa template vào file header(.h) thay vì file cpp.

Best practice

Các mẫu cần thiết trong nhiều tệp phải được xác định trong tệp tiêu đề, sau đó #included bất cứ khi nào cần. Điều này cho phép trình biên dịch xem định nghĩa mẫu đầy đủ và khởi tạo mẫu khi cần.