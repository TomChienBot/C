[Numeric conversions](https://www.learncpp.com/cpp-tutorial/numeric-conversions/)

Bất kỳ chuyển đổi loại nào được quy định trong quy tắc numeric promotion  là  numeric promotion, not a numeric conversion.

1. Có năm loại chuyển đổi numeric conversion cơ bản:
    1. Converting an integral type to any other integral type
    short s = 3; // convert int to short
    long l = 3; // convert int to long
    char ch = s; // convert short to char
    unsigned int u = 3; // convert int to unsigned int
    2. Converting a floating point type to any other floating point type
    float f = 3.0; // convert double to float
    long double ld = 3.0; // convert double to long double
    3. Converting a floating point type to any integral type:
    int i = 3.5; // convert double to int
    4. Converting an integral type to any floating point type:
    double d = 3; // convert int to double
    5. Converting an integral type or a floating point type to a bool:
    bool b1 = 3; // convert int to bool
    bool b2 = 3.0; // convert double to bool

2. Safe and potentially unsafe conversions

Không giống như numeric promotion(Cái luôn bảo toàn giá trị, do đó nó an toàn), một vài numeric conversions không bảo toàn giá trị trong trường hợp nhất định. Nhưng trường hợp này được cho là  "có khả năg ko an toàn"

Numeric conversion được cho là an toàn nếu rơi vào 1 tronng 3 loại sau:
    1. chuyển đổi bảo toàn giá trị là numeric conversions khi kiểu cần chuyển đổi bảo toàn chính xác các giá trị ở kiểu nguồn
    Ví dụ: int to long, short to double
        int n { 5 };
        long l = n; // okay, produces long value 5

        short s { 5 };
        double d = s; // okay, produces double value 5.0

    2. Reinterpretive conversions  là các chuyển đổi số có khả năng không an toàn trong đó kết quả có thể nằm ngoài phạm vi của loại nguồn. Chuyển đổi signed/ unsigned rơi vào danh mục này.
    Ví dụ:
        int n1 { 5 };
        unsigned int u1 { n1 }; // okay: will be converted to unsigned int 5 (value preserved)

        int n2 { -5 };
        unsigned int u2 { n2 }; // bad: will result in large integer outside range of signed int

    ở th2: signed int value (-5) được chuyển đổi thành unsigned int. Vì unsigned int ko biểu diễn được giá trị âm => kết quả ko đc bảo toàn trong trường hợp này.

    3. Lossy conversions là các chuyển đổi số có khả năng không an toàn, trong đó một số dữ liệu có thể bị mất trong quá trình chuyển đổi.
    Ví dụ: double to int
    int i = 3.0; // okay: will be converted to int value 3 (value preserved)
    int j = 3.5; // data lost: will be converted to int value 3 (fractional value 0.5 lost)

    double to float:
    float f = 1.2;        // okay: will be converted to float value 1.2 (value preserved)
    float g = 1.23456789; // data lost: will be converted to float 1.23457 (precision lost)

3. More on numeric conversions
Các quy tắc cụ thể cho việc chuyển đổi số rất phức tạp và nhiều, vì vậy đây là những điều quan trọng nhất cần nhớ:
Trong mọi trường hợp, việc chuyển đổi một giá trị thành một loại có phạm vi không hỗ trợ giá trị đó sẽ dẫn đến kết quả có thể không mong đợi. 
Ví dụ:
    int i{ 30000 };
    char c = i; // chars have range -128 to 127

    std::cout << static_cast<int>(c) << '\n';

Nó dẫn đến kiểu char bị tràn và tạo ra kết quả không mong muốn như ở ví dụ trên là 48 chứ ko phải 30000

Việc chuyển đổi từ loại dấu phẩy động hoặc tích phân lớn hơn sang loại nhỏ hơn từ cùng một họ thường sẽ hoạt động miễn là giá trị phù hợp với phạm vi của loại nhỏ hơn. 
Ví dụ:
    int i{ 2 };
    short s = i; // convert from int to short
    std::cout << s << '\n';

    double d{ 0.1234 };
    float f = d;
    std::cout << f << '\n';

Việc chuyển đổi từ số nguyên sang số dấu phẩy động thường hoạt động miễn là giá trị nằm trong phạm vi của loại dấu phẩy động
ví dụ:
    int i{ 10 };
    float f = i;
    std::cout << f << '\n';