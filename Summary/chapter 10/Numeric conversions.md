[Numeric conversions](https://www.learncpp.com/cpp-tutorial/numeric-conversions/)

Bất kỳ chuyển đổi loại nào được quy định trong quy tắc numeric promotion  là  numeric promotion, not a numeric conversion.

1. Có năm loại chuyển đổi số cơ bản
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
    
