[Type deduction for objects using the auto keyword](https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/)

1. Type deduction for initialized variables

Type deduction (also sometimes called type inference) là một tính năng cho phép trình biên dịch suy ra loại đối tượng từ bộ khởi tạo của đối tượng. Để sử dụng type deduction cùng với biến, từ khóa auto được sử dụng thay cho loại biến:

Ví dụ:
auto d{ 5.0 }; // 5.0 is a double literal, so d will be type double
auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int
auto x { i }; // i is an int, so x will be type int too

Trường hợp đầu, vì 5.0 là chữ ghép nên trình biên dịch sẽ suy ra biến d có kiểu dữ liệu double

Ví dụ 2:
int main()
{
    auto a { 1.23f }; // f suffix causes a to be deduced to float
    auto b { 5u };    // u suffix causes b to be deduced to unsigned int

    return 0;
}

Ví dụ 3:

void foo()
{
}

int main()
{
    auto x;          // The compiler is unable to deduce the type of x
    auto y{ };       // The compiler is unable to deduce the type of y
    auto z{ foo() }; // z can't have type void, so this is invalid
}

2. Type deduction drops const / constexpr qualifiers

Trong hầu hết th, type deduction sẽ bỏ const hoặc constexpr khỏi kiểu dữ liệu được suy luận.
Ví dụ:

    const int x { 5 }; // x has type const int
    auto y { x };      // y will be type int (const is dropped)

Nếu bạn muốn suy ra là const hoặc constexpr, bạn phải tự cung cấp const hoặc constexpr

Ví dụ:
    const int x { 5 };  // x has type const int (compile-time const)
    auto y { x };       // y will be type int (const is dropped)

    constexpr auto z { x }; // z will be type constexpr int (constexpr is reapplied)

3. Type deduction for string literals

auto s { "Hello, world" }; // s will be type const char*, not std::string

Nếu bạn muốn kiểu được suy ra từ một chuỗi ký tự là std::string hoặc std::string_view, bạn sẽ cần sử dụng hậu tố bằng chữ s hoặc sv

Ví dụ:

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view

4. Type deduction benefits and downsides
Benefits:
    1. giúp dễ đọc hơn
    2. giúp tránh các biến khởi tạo ngoài ý muốn
        int x; // oops, we forgot to initialize x, but the compiler may not complain
        auto y; // the compiler will error out because it can't deduce a type for y
Downsides
    1. Auto có thể suy luận ra kiểu dữ liệu không mong muốn: 

    auto y { 5 }; // oops, we wanted a double here but we accidentally provided an int literal

Best practice:
Sử dụng type deduction cho các biến của bạn khi loại đối tượng không quan trọng.

Ưu tiên  rõ ràng khi bạn yêu cầu một loại cụ thể khác với loại của trình khởi tạo hoặc khi đối tượng của bạn được sử dụng trong ngữ cảnh mà việc làm cho loại đó trở nên rõ ràng là hữu ích.

