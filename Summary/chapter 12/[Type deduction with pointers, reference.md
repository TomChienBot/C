[Type deduction with pointers, references, and const](https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/#google_vignette)

1. Type deduction drops references

Ngoài việc loại bỏ const, việc suy luận kiểu cũng sẽ loại bỏ các tham chiếu:

    #include <string>

    std::string& getRef(); // some function that returns a reference

    int main()
    {
        auto ref { getRef() }; // type deduced as std::string (not std::string&)

        return 0;
    }

Trong ví dụ trên, biến ref đang sử dụng suy luận kiểu. Mặc dù hàm getRef() trả về một std::string&, nhưng reference qualifier bị loại bỏ, do đó loại ref được suy ra là std::string.

Giống như const neeys muốn suy luận kiểu ra tham chiếu, Cần phải áp dụng tham chiếu tại thời điểm định nghĩa.

    #include <string>

    std::string& getRef(); // some function that returns a reference

    int main()
    {
        auto ref1 { getRef() };  // std::string (reference dropped)
        auto& ref2 { getRef() }; // std::string& (reference reapplied)

        return 0;
    }

2. Top-level const and low-level const

top-level const dùng để chỉ chính đối tượng được khai báo với const. Nói cách khác, nó xác định rằng giá trị nội tại của đối tượng đó không thể thay đổi.

    const int x;    // this const applies to x, so it is top-level
    int* const ptr; // this const applies to ptr, so it is top-level

low-level const là const qualifier áp dụng cho đối tượng thông qua tham chiếu hoặc được trỏ tới:

    const int& ref; // this const applies to the object being referenced, so it is low-level
    const int* ptr; // this const applies to the object being pointed to, so it is low-level

Tham chiếu đến giá trị const luôn là low-level const. Một con trỏ có thể có top-level const, low-level const hoặc cả hai loại const

    const int* const ptr; // the left const is low-level, the right const is top-level

3. Type deduction and const references

Nếu khởi tạo là một tham chiếu đến const(or constexpr) thì tham chiếu sẽ bị loại bỏ trước tiên, theo sau đó là top-level const bị loại bỏ khỏi kết quả.

    #include <string>

    const std::string& getConstRef(); // some function that returns a reference to const

    int main()
    {
        auto ref1{ getConstRef() }; // std::string (reference dropped, then top-level const dropped from result)

        return 0;
    }

key insight:
    Việc loại bỏ một tham chiếu có thể thay đổi một low-level const thành một top- level const: const std::string& là một  low-level const, nhưng việc loại bỏ tham chiếu sẽ mang lại const std::string, là một top- level const.

Giải pháp:

    #include <string>

    const std::string& getConstRef(); // some function that returns a const reference

    int main()
    {
        auto ref1{ getConstRef() };        // std::string (reference and top-level const dropped)
        const auto ref2{ getConstRef() };  // const std::string (reference dropped, const reapplied)

        auto& ref3{ getConstRef() };       // const std::string& (reference reapplied, low-level const not dropped)
        const auto& ref4{ getConstRef() }; // const std::string& (reference and const reapplied)

        return 0;
    }

Best practice:
    Nếu bạn muốn tham chiếu const, hãy áp dụng lại vòng loại const ngay cả khi nó không thực sự cần thiết, vì nó làm cho ý định của bạn rõ ràng và giúp ngăn ngừa sai sót.

4. What about constexpr references?

Nó hoạt động giống như tham chiếu const

    #include <string_view>

    constexpr std::string_view hello { "Hello" };

    constexpr const std::string_view& getConstRef()
    {
        return hello;
    }

    int main()
    {
        auto ref1{ getConstRef() };            // std::string_view (top-level const and reference dropped)
        constexpr auto ref2{ getConstRef() };  // constexpr std::string_view (constexpr reapplied, reference dropped)

        auto& ref3{ getConstRef() };           // const std::string_view& (reference reapplied, low-level const not dropped)
        constexpr auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)

        return 0;
    }

5. Type deduction and pointers

Không giống tham chiếu, việc suy luận hàm không loại bỏ con trỏ

    #include <string>

    std::string* getPtr(); // some function that returns a pointer

    int main()
    {
        auto ptr1{ getPtr() }; // std::string*

        return 0;
    }

Ta cũng có thể sử dụng dấu hoa thị * với suy đoán kiểu con trỏ.

    #include <string>

    std::string* getPtr(); // some function that returns a pointer

    int main()
    {
        auto ptr1{ getPtr() };  // std::string*
        auto* ptr2{ getPtr() }; // std::string*

        return 0;
    }

6. The difference between auto and auto* 

Hầu hết trường hợp thì hiểu quả sử dụng là như nhau

Tuy nhiên, có một số khác biệt giữa auto và auto* trong thực tế:

Đầu tiên, auto* phải phân giải thành trình khởi tạo con trỏ, nếu không sẽ xảy ra lỗi biên dịch:

    #include <string>

    std::string* getPtr(); // some function that returns a pointer

    int main()
    {
        auto ptr3{ *getPtr() };      // std::string (because we dereferenced getPtr())
        auto* ptr4{ *getPtr() };     // does not compile (initializer not a pointer)

        return 0;
    }

7. Type deduction and const pointers

Vì con trỏ không bị loại bỏ nên chúng ta không phải lo lắng về điều đó. Nhưng với con trỏ, chúng ta có cả con trỏ const và con trỏ tới các trường hợp const để suy nghĩ, đồng thời chúng ta cũng có auto và auto*

    #include <string>

    int main()
    {
        std::string s{};
        const std::string* const ptr { &s };

        auto ptr1{ ptr };  // const std::string*
        auto* ptr2{ ptr }; // const std::string*

        auto const ptr3{ ptr };  // const std::string* const
        const auto ptr4{ ptr };  // const std::string* const

        auto* const ptr5{ ptr }; // const std::string* const
        const auto* ptr6{ ptr }; // const std::string*

        const auto const ptr7{ ptr };  // error: const qualifer can not be applied twice
        const auto* const ptr8{ ptr }; // const std::string* const

        return 0;
    }

Best practice:

    Nếu bạn muốn một con trỏ const, hãy áp dụng lại vòng loại const ngay cả khi nó không thực sự cần thiết, vì nó làm cho ý định của bạn rõ ràng và giúp ngăn ngừa sai sót.