[Function templates with multiple template types](https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/#google_vignette)

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n';  // compile error

    return 0;
}

Trong lệnh gọi hàm max(2, 3.5), chúng ta đang truyền các đối số thuộc hai loại khác nhau: một kiểu int và một kiểu double. Vì chúng ta đang thực hiện lệnh gọi hàm mà không sử dụng dấu ngoặc nhọn để chỉ định loại thực tế nên trước tiên trình biên dịch sẽ xem xét liệu có kết quả khớp không phải mẫu nào cho max(int, double) hay không. Nó sẽ không tìm thấy.

1. Use static_cast to convert the arguments to matching types
Giải pháp đầu tiên cho vấn đề này.

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)

    return 0;
}

2. Provide an explicit type template argument
Không phải sử dụng dự đoán đối số mẫu nếu  chỉ định một đối số mẫu rõ ràng sẽ được sử dụng thay thế:

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    // we've explicitly specified type double, so the compiler won't use template argument deduction
    std::cout << max<double>(2, 3.5) << '\n';

    return 0;
}

Ở đây ta đã chỉ đinh rõ ràng T sẽ thay thế với double. Nên trình biên dịch sẽ không cần phải suy luận kiểu đối số. Thay vào đó, nó sẽ khởi tạo hàm max<double>(double, double). Đối số 2(int) sẽ được ngầm chuyển đổi sang dạng double.

3. Function templates with multiple template type parameters

Cách tốt nhất để giải quyết vấn đề này là viết lại mẫu hàm của chúng ta theo cách mà các tham số của chúng ta có thể phân giải thành các loại khác nhau. Thay vì sử dụng một tham số loại mẫu T, giờ đây chúng tôi sẽ sử dụng hai tham số (T và U):

ví dụ:

#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // resolves to max<int, double>

    return 0;
}

Khi đã xác định x với loại mẫu T và y với loại mẫu U, x và y giờ đây có thể giải quyết các loại của chúng một cách độc lập. Khi chúng ta gọi max(2, 3.5), T có thể là int và U có thể là double. Trình biên dịch sẽ vui vẻ khởi tạo max<int, double>(int, double) cho chúng ta.'

4. Abbreviated function templates C++20 (Mẫu hàm viết tắt)

C++20 giới thiệu một cách sử dụng mới của từ khóa auto: Khi từ khóa auto được sử dụng làm loại tham số trong hàm thông thường, trình biên dịch sẽ tự động chuyển đổi hàm thành mẫu hàm với mỗi tham số auto trở thành tham số loại mẫu độc lập. Phương pháp tạo mẫu hàm này được gọi là mẫu hàm viết tắt.

ví dụ

auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}

Trong trường hợp bạn muốn mỗi tham số loại mẫu là một loại độc lập, biểu mẫu này được ưu tiên vì việc loại bỏ dòng khai báo tham số mẫu giúp mã của bạn ngắn gọn và dễ đọc hơn.


Best practice:

Thoải mái sử dụng các mẫu hàm viết tắt với một tham số tự động duy nhất hoặc trong đó mỗi tham số tự động phải là một loại độc lập (và tiêu chuẩn ngôn ngữ của bạn được đặt thành C++20 hoặc mới hơn).