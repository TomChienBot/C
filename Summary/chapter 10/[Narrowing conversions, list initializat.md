[Narrowing conversions, list initialization, and constexpr initializers](https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/)

1. Narrowing conversions

chuyển đổi thu hẹp là chuyển đổi số có khả năng không an toàn trong đó loại đích có thể không chứa được tất cả các giá trị của loại nguồn.
Các chuyển đổi sau đây được xác định là thu hẹp:
From a floating point type to an integral type.
From a floating point type to a narrower or lesser ranked floating point type
From an integral to a floating point type, trừ khi giá trị được chuyển đổi là constexpr
From an integral type to another integral type that cannot represent all values of the original type

Best practice:
Vì chúng có thể không an toàn và là nguồn gây ra lỗi nên hãy tránh goi han số lượt chuyển đổi bất cứ khi nào có thể.

2. Make intentional narrowing conversions explicit
narrowing conversions không phải lúc nào cũng có thể tránh được, Điều này đặc biệt đúng khi gọi hàm, Nơi mà tham số hàm và đối số có thể không trùng kiểu dữ liệu và yêu cầu phải chuyển đổi thu hẹp.

Ví dụ:
    void printInt(int value) {
    std::cout << value << std::endl;
    }

    int main() {
    double pi = 3.14159;
    // Chuyển đổi thu hẹp từ 'double' sang 'int' khi gọi hàm
    printInt(pi); // Cảnh báo: implicit narrowing conversion
    // Cách tốt hơn: sử dụng static_cast để chuyển đổi một cách rõ ràng
    printInt(static_cast<int>(pi)); // Không cảnh báo, chuyển đổi rõ ràng
    return 0;
    }

Best practice:
    Nếu bạn cần thực hiện chuyển đổi thu hẹp, hãy sử dụng static_cast để chuyển đổi nó thành chuyển đổi rõ ràng.

Chuyển đổi rõ ràng (explicit conversion):
    là quá trình mà lập trình viên cố ý yêu cầu trình biên dịch thực hiện một chuyển đổi kiểu dữ liệu từ một kiểu này sang kiểu khác. Điều này thường được thực hiện bằng cách sử dụng các toán tử ép kiểu như static_cast, dynamic_cast, const_cast, hoặc reinterpret_cast1.

    Ví dụ:
    bạn đã đưa ra, static_cast<int>(pi), là một chuyển đổi rõ ràng từ kiểu double sang kiểu int. Điều này nói với trình biên dịch rằng bạn muốn chuyển đổi giá trị của pi thành một số nguyên, và bạn đã chấp nhận mọi hậu quả của việc làm tròn hoặc cắt bỏ phần thập phân.

    Chuyển đổi rõ ràng khác với chuyển đổi ngầm định (implicit conversion), nơi trình biên dịch tự động thực hiện chuyển đổi mà không cần sự can thiệp của lập trình viên.

3. Brace initialization disallows narrowing conversions
    Thu hẹp chuyển đổi không được phép khi sử dụng khởi tạo dấu ngoặc nhọn. Ví dụ:
    int i { 3.5 }; // won't compile

Nếu thực sự muốn thu hẹp chuyển đổi trong dấu ngoặc nhọn, sử dụng static_cast để chuyển đổi chuyển đổi thu hẹp thành chuyển đổi rõ ràng:
    double d { 3.5 };

    // static_cast<int> converts double to int, initializes i with int result

    int i { static_cast<int>(d) };

Vẫn có thể thực hiện nhưng sẽ có warning. nếu thêm static_cast => mất warning.
4. Some constexpr conversions aren’t considered narrowing
Chuyển Đổi Thu Hẹp: Chuyển đổi thu hẹp xảy ra khi một giá trị của một kiểu được chuyển đổi sang một kiểu khác không thể biểu diễn tất cả các giá trị của kiểu gốc. Ví dụ, chuyển đổi từ double sang int có thể mất thông tin nếu giá trị double có phần thập phân.

constexpr và Chuyển Đổi Thu Hẹp: Khi một giá trị constexpr được chuyển đổi sang một kiểu khác, nếu giá trị có thể được lưu trữ chính xác trong kiểu đích, nó không được coi là chuyển đổi thu hẹp. Điều này là bởi vì giá trị được biết tại thời điểm biên dịch, và trình biên dịch có thể xác minh rằng chuyển đổi là an toàn.

Ví dụ: 
{
    constexpr double myDouble = 3.14;
    constexpr int myInt = myDouble; // Đây ko phải là chuyển đổi thu hẹp
}

5. List initialization with constexpr initializers (Khởi tạo danh sách với trình khởi tạo constexpr)

Các mệnh đề ngoại lệ constexpr này cực kỳ hữu ích khi khởi tạo danh sách các đối tượng không phải int/ double, vì chúng ta có thể sử dụng giá trị khởi tạo int hoặc double (hoặc đối tượng constexpr).

Ví dụ:
int main()
{
    // We can avoid literals with suffixes
    unsigned int u { 5 }; // okay (we don't need to use `5u`)
    float f { 1.5 };      // okay (we don't need to use `1.5f`)

    // We can avoid static_casts
    constexpr int n{ 5 };
    double d { n };       // okay (we don't need a static_cast here)
    short s { 5 };        // okay (there is no suffix for short, we don't need a static_cast here)

    return 0;
}
