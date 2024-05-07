[std::optional](https://www.learncpp.com/cpp-tutorial/stdoptional/)

1. Returning a std::optional

C++ 17 đã giới thiệu std::optional, là loại mẫu lớp thực hiện một giá trị tùy chọn. Nghĩa là, std::Optional<T> có thể có giá trị loại T hoặc không. Chúng ta có thể sử dụng điều này để thực hiện tùy chọn thứ ba ở trên

    #include <iostream>
    #include <optional> // for std::optional (C++17)

    // Our function now optionally returns an int value
    std::optional<int> doIntDivision(int x, int y)
    {
        if (y == 0)
            return {}; // or return std::nullopt
        return x / y;
    }

    int main()
    {
        std::optional<int> result1 { doIntDivision(20, 5) };
        if (result1) // if the function returned a value
            std::cout << "Result 1: " << *result1 << '\n'; // get the value
        else
            std::cout << "Result 1: failed\n";

        std::optional<int> result2 { doIntDivision(5, 0) };

        if (result2)
            std::cout << "Result 2: " << *result2 << '\n';
        else
            std::cout << "Result 2: failed\n";

        return 0;
    }

Kết quả:

    Result 1: 4
    Result 2: failed

Sử dụng std::Options khá dễ dàng. Chúng ta có thể xây dựng một std::Optional<T> có giá trị hoặc không:

    std::optional<int> o1 { 5 };            // initialize with a value
    std::optional<int> o2 {};               // initialize with no value
    std::optional<int> o3 { std::nullopt }; // initialize with no value


Lưu ý rằng std::Options có cú pháp sử dụng về cơ bản giống với con trỏ:


    Behavior	                         Pointer	                            std::optional
    Hold no value	    initialize/assign {} or std::nullptr	            initialize/assign {} or std::nullopt
    Hold a value	    initialize/assign an address	                    initialize/assign a value
    Check if has value	implicit conversion to bool                         implicit conversion to bool or has_value()
    Get value	        dereference	                                        dereference or value()

Tuy nhiên về mặt ngữ nghĩa, con trỏ và std::optional có chút khác biệt:

    Con trỏ tham chiếu đến 1 đối tượng và thực hiện phép gán bản copy cho con trỏ chứ không phải đối tượng. Nếu chúng ta trả về con trỏ 1 địa chỉ, nó sẽ gửi bản copy địa chỉ cho hàm gọi. Và khi đối tượng bị hủy, con trỏ sẽ treo. 

    Std::optional thì khác, Khi gán một giá trị cho std::optional, bản sao của giá trị đó được lưu trữ trong std::optional.Khi bạn trả về std::optional chứa giá trị, bạn không thực sự chuyển giá trị bên trong sang hàm gọi.
    Thay vào đó, bạn chuyển một đối tượng std::optional chứa giá trị đó.

2. Pros and cons of returning a std::optional

Pros:
    Sử dụng std::Options sẽ ghi lại một cách hiệu quả rằng một hàm có thể trả về một giá trị hay không.
    Chúng ta không cần phải nhớ giá trị nào đang được trả về dưới dạng trọng điểm.
    Cú pháp sử dụng std::Optional rất thuận tiện và trực quan.
cons:
    Chúng ta phải đảm bảo std::Options chứa một giá trị trước khi nhận giá trị. Nếu chúng tôi hủy đăng ký một std::Optional không chứa giá trị, chúng tôi sẽ nhận được hành vi không xác định.
    std::Optional chọn không cung cấp cách truyền lại thông tin về lý do tại sao chức năng không thành công.

3. Using std::optional as an optional function parameter

std::optional là một cách khác để hàm chấp nhận đối số tùy chọn, thay vì: 

    #include <iostream>

    void printIDNumber(const int *id=nullptr)
    {
        if (id)
            std::cout << "Your ID number is " << *id << ".\n";
        else
            std::cout << "Your ID number is not known.\n";
    }

    int main()
    {
        printIDNumber(); // we don't know the user's ID yet

        int userid { 34 };
        printIDNumber(&userid); // we know the user's ID now

        return 0;
    }

có thể làm ntn:

    #include <iostream>
    #include <optional>

    void printIDNumber(std::optional<const int> id = std::nullopt)
    {
        if (id)
            std::cout << "Your ID number is " << *id << ".\n";
        else
            std::cout << "Your ID number is not known.\n";
    }

    int main()
    {
        printIDNumber(); // we don't know the user's ID yet

        int userid { 34 };
        printIDNumber(userid); // we know the user's ID now

        printIDNumber(62); // we can also pass an rvalue

        return 0;
    }

Có hai ưu điểm của phương pháp này:
    1. Nó ghi lại một cách hiệu quả rằng tham số là tùy chọn.
    2. Chúng tôi có thể chuyển vào một giá trị (vì std::Optional sẽ tạo một bản sao).

Tuy nhiên, vì std::Optionals tạo một bản sao đối số của nó, điều này trở thành vấn đề khi T "expensive" để sao chép.