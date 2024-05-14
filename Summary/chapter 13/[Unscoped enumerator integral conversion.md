[Unscoped enumerator integral conversions](https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/)

Chúng ta đã đề cập các thành phần liệt kê (enumerators) là những hằng số biểu tượng. 

Những enumerators cũng có giá trị thuộc loại số nguyên

Nó gần giống với trường hợp của chars

Khi chúng ta định nghĩa 1 enumeration, từng enumerator sẽ tự động được liên kết với một giá trị số nguyên dựa trên vị trí của nó trong danh sách enumerator

Theo mặc định , enumerator đầu tiên được cung cấp giá trị 0, mỗi enumerator tiếp theo có giá trị lơn hơn enumerator trước đó.

ví dụ:
    enum Color
    {
        black,   // 0
        red,     // 1
        blue,    // 2
        green,   // 3
        white,   // 4
        cyan,    // 5
        yellow,  // 6
        magenta, // 7
    };

    int main()
    {
        Color shirt{ blue }; // shirt actually stores integral value 2

        return 0;
    }

Có thể xác định rõ ràng giá trị của enumerators. Những giá trị nguyên có thể âm hoặc dương. Các enumerator cũng có thể chia sể cùng 1 giá trị

ví dụ:

    enum Animal
    {
        cat = -3,    // values can be negative
        dog,         // -2
        pig,         // -1
        horse = 5,
        giraffe = 5, // shares same value as horse
        chicken,     // 6
    };

Trong trường hợp này ngựa và cao cổ đều có cùng giá trị 5. Khi điều này xảy ra, các enumerator trở nên không khác biệt và có thể hoán đổi cho nhau. Mặc dù C++ cho phép gán chung 1 giá trị trong cùng 1 enumeration nhưng nên tránh.

Best practice:
    Tránh gán các giá trị rõ ràng cho các enumerators trừ khi bạn có lý do thuyết phục để làm như vậy.

1. Value-initializing an enumeration

Nếu 1 enumeration được khởi tạo bằng 0, enumeration sẽ có giá trị 0 ngay cả khi không có enumerator nào có giá trị 0

    #include <iostream>

    enum Animal
    {
        cat = -3,    // -3
        dog,         // -2
        pig,         // -1
        // note: no enumerator with value 0 in this list
        horse = 5,   // 5
        giraffe = 5, // 5
        chicken,     // 6
    };

    int main()
    {
        Animal a {}; // value-initialization zero-initializes a to value 0
        std::cout << a; // prints 0

        return 0;
    }

Nếu kiểu liệt kê có một enumerator có giá trị 0, thì khi khai báo một biến kiểu enumeration mà không khởi tạo giá trị cụ thể, biến đó sẽ được khởi tạo bằng giá trị của enumerator đó.

Ví dụ: 

    enum Color {
    RED = 0,
    GREEN,
    BLUE
    };

    Color myColor1; // Không khởi tạo giá trị cụ thể
    Color myColor2 = RED; // Khởi tạo bằng giá trị RED

    // In ra giá trị của biến
    std::cout << myColor1 << std::endl; // In ra RED
    std::cout << myColor2 << std::endl; // In ra RED

Khi không có enumerator nào có giá trị 0, khởi tạo mặc định dễ dẫn đến lỗi logic

Ví dụ:


    enum Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY
    };

    Day today; // Không khởi tạo giá trị cụ thể

Trong ví dụ này, Day không có enumerator nào bằng 0. Do đó, việc khởi tạo mặc định cho biến today trở nên không xác định. Biến today có thể được gán bất kỳ giá trị nào (ví dụ: -1, 10) tùy thuộc vào ngôn ngữ lập trình.

Best practice:

    Tạo hằng số liệt kê có giá trị 0 là cách tốt nhất để cho bảng liệt kê. Nếu khổn có enumerator nào phù hợp làm mặc định (mang giá trị 0) hãy cần nhắc thêm "invalid" hoặc "unknowm" enumerator có giá trị 0 để đảm bảo tính rõ ràng và xử lí các trường hợp đặc biệt.
ví dụ:

    enum GameState {
    UNKNOWN = 0,  // Không thể xác định trạng thái ban đầu
    PLAYING,
    PAUSED,
    FINISHED
    };

2. Unscoped enumerations will implicitly convert to integral values

Mặc dù , enumeration lưu giữ giá trị nguyên, nhưng chúng không phải là kiểu dữ liệu nguyên (chúng là kiểu dữ liệu kết hợp (compound type)). Tuy nhiên, unscoped enumeration sẽ ngầm chuyển đổi tới giá trị nguyên. 

Ví dụ: 

    #include <iostream>

    enum Color
    {
        black, // assigned 0
        red, // assigned 1
        blue, // assigned 2
        green, // assigned 3
        white, // assigned 4
        cyan, // assigned 5
        yellow, // assigned 6
        magenta, // assigned 7
    };

    int main()
    {
        Color shirt{ blue };

        std::cout << "Your shirt is " << shirt << '\n'; // what does this do?

        return 0;
    }

Kết quả nó in ra sẽ là: 

    Your shirt is 2

3. Enumeration size and underlying type (base)

Underlying type (kiểu cơ sở) là kiểu dữ liệu cơ bản được sử dụng để lưu trữ giá trị của một kiểu dữ liệu khác trừu tượng hơn. Nói cách khác, nó là kiểu dữ liệu thực tế mà một kiểu dữ liệu trừu tượng được xây dựng dựa trên.

Ví dụ:
    Trong lập trình, ta có thể định nghĩa kiểu dữ liệu trừu tượng Color để biểu diễn màu sắc. Tuy nhiên, Color không phải là kiểu dữ liệu thực tế mà chỉ là một khái niệm trừu tượng. Để lưu trữ giá trị của một biến kiểu Color, ta cần sử dụng một kiểu dữ liệu cơ sở như int (số nguyên) hoặc char (ký tự).

4. Integer to unscoped enumerator conversion

Mặc dù trình biên dịch sẽ ngầm chuyển đổi một bảng liệt kê không có phạm vi thành một số nguyên, nhưng nó sẽ không ngầm chuyển đổi một số nguyên thành một bảng liệt kê không có phạm vi.

    enum Pet // no specified base
    {
        cat, // assigned 0
        dog, // assigned 1
        pig, // assigned 2
        whale, // assigned 3
    };

    int main()
    {
        Pet pet { 2 }; // compile error: integer value 2 won't implicitly convert to a Pet
        pet = 3;       // compile error: integer value 3 won't implicitly convert to a Pet

        return 0;
    }

Có hai cách để giải quyết vấn đề này

1. sử dụng static_cast:

    enum Pet // no specified base
    {
        cat, // assigned 0
        dog, // assigned 1
        pig, // assigned 2
        whale, // assigned 3
    };

    int main()
    {
        Pet pet { static_cast<Pet>(2) }; // convert integer 2 to a Pet
        pet = static_cast<Pet>(3);       // our pig evolved into a whale!

        return 0;
    }

2. Thứ hai, kể từ C++ 17, nếu một bảng liệt kê không có phạm vi có cơ sở được chỉ định rõ ràng, thì trình biên dịch sẽ cho phép bạn khởi tạo danh sách một bảng liệt kê không có phạm vi bằng cách sử dụng một giá trị nguyên

    enum Pet: int // we've specified a base
    {
        cat, // assigned 0
        dog, // assigned 1
        pig, // assigned 2
        whale, // assigned 3
    };

    int main()
    {
        Pet pet1 { 2 }; // ok: can brace initialize unscoped enumeration with specified base with integer (C++17)
        Pet pet2 (2);   // compile error: cannot direct initialize with integer
        Pet pet3 = 2;   // compile error: cannot copy initialize with integer

        pet1 = 3;       // compile error: cannot assign with integer

        return 0;
    }