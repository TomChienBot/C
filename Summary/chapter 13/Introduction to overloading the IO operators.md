[Introduction to overloading the I/O operators](https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/)

    #include <iostream>
    #include <string_view>

    enum Color
    {
        black,
        red,
        blue,
    };

    constexpr std::string_view getColorName(Color color)
    {
        switch (color)
        {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???";
        }
    }

    int main()
    {
        constexpr Color shirt{ blue };

        std::cout << "Your shirt is " << getColorName(shirt) << '\n';

        return 0;
    }

Ở ví dụ trên sử dụng hàm để chuyển đổi 1 bảng liệt kê thành 1 chuỗi

Ví dụ trên hoạt động có vẻ tốt những có 2 nhược điểm sau

    1. ta phải nhớ tên của hàm tạo ra
    2. Việc phải gọi hàm làm tăng sự lộn xộn cho câu lệnh đầu ra.

Lí tưởng nhất là ta có thể dạy toán tử << out ra 1 hằng số liệt kê
    ta có thể làm như sau:
    std::cout << shirt

1. Introduction to operator overloading

Quá tải toán tử là một tính năng cho phép bạn định nghĩa lại ý nghĩa của các toán tử trong ngôn ngữ lập trình để áp dụng cho các kiểu dữ liệu do người dùng định nghĩa.

Nói cách khác, bạn có thể tạo ra các hàm mới có các ký hiệu toán tử quen thuộc như +, -, *, =, v.v. để thực hiện các thao tác cụ thể cho các kiểu dữ liệu của riêng bạn.

Toán tử xếp chồng cơ bản khá đơn giản

    Xác định hàm bằng cách sử dụng tên của toán tử làm tên hàm

    Thêm tham số có kiểu thích hợp cho mỗi toán hạng. Một trong các tham số này phải là kiểu dữ liệu do người dùng xác định(kiểu class hoặc loại enum), nếu không trình biên dịch sẽ gặp lỗi.

    Đặt kiểu trả về thành bất kì kiểu dữ liều nào có ý nghĩa.
    Sử dụng câu lệnh return để trả về kết quả của toán tử

2. Overloading operator<< to print an enumerator 

Giả sử ta có biểu thức đơn giản: std::cout << 5 và std :: cout thuộc kiểu dữ liệu std::ostream và 5 là chữ số thuộc kiểu int.

Khi biểu thức được đánh giá, Trình biên dịch sẽ tìm kiếm cho toán tử nạp chồng << hàm có thể xử lí các tham số thuộc kiểu std::ostream và int. Trình biên dịch sẽ tìm kiếm và gọi hàm operator<< phù hợp để xuất dữ liệu ra màn hình. Hàm này trả về đối tượng bên trái của nó, cho phép bạn sử dụng chuỗi các toán tử << để xuất nhiều giá trị cùng một lệnh.

Ví dụ:

    #include <iostream>
    #include <string_view>

    enum Color
    {
        black,
        red,
        blue,
    };

    constexpr std::string_view getColorName (Color color)
    {
        switch color
        {
            case black:     return "black";
            case red:       return "red";
            case blue:      return "blue";
            default:        return "???":
        }
    }

    std::ostream& operator<<(std::ostream& out, Color color)
    {
        out << getColorName(color)
        return out;
    }

    int main()
    {
        Color shirt{blue};
        std::cout << " Your shirt is " << shirt << '\n' ;
        return 0;
    }

3. Overloading operator>> to input an enumerator 

    #include <iostream>
    #include <limits>
    #include <optional>
    #include <string>
    #include <string_view>

    enum Pet
    {
        cat,   // 0
        dog,   // 1
        pig,   // 2
        whale, // 3
    };

    constexpr std::string_view getPetName(Pet pet)
    {
        switch (pet)
        {
        case cat:   return "cat";
        case dog:   return "dog";
        case pig:   return "pig";
        case whale: return "whale";
        default:    return "???";
        }
    }

    constexpr std::optional<Pet> getPetFromString(std::string_view sv)
    {
        if (sv == "cat")   return cat;
        if (sv == "dog")   return dog;
        if (sv == "pig")   return pig;
        if (sv == "whale") return whale;

        return {};
    }

    // pet is an in/out parameter
    std::istream& operator>>(std::istream& in, Pet& pet)
    {
        std::string s{};
        in >> s; // get input string from user

        std::optional<Pet> match { getPetFromString(s) };
        if (match) // if we found a match
        {
            pet = *match; // set Pet to the matching enumerator
            return in;
        }

        // We didn't find a match, so input must have been invalid
        // so we will set input stream to fail state
        in.setstate(std::ios_base::failbit);

        // On an extraction failure, operator>> zero-initializes fundamental types
        // Uncomment the following line to make this operator do the same thing
        // pet = {};

        return in;
    }

    int main()
    {
        std::cout << "Enter a pet: cat, dog, pig, or whale: ";
        Pet pet{};
        std::cin >> pet;

        if (std::cin) // if we found a match
            std::cout << "You chose: " << getPetName(pet) << '\n';
        else
        {
            std::cin.clear(); // reset the input stream to good
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Your pet was not valid\n";
        }

        return 0;
    }
