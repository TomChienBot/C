[Converting an enumeration to and from a string](https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/)

    #include <iostream>

    enum Color
    {
        black, // 0
        red,   // 1
        blue,  // 2
    };

    int main()
    {
        Color shirt{ blue };

        std::cout << "Your shirt is " << shirt << '\n';

        return 0;
    }

kết quả in ra:

    Your shirt is 2

Bởi vì toán tử << không biết làm sao để in ra color, Trình biên dịch sẽ ngầm chuyển đổi color sang giá trị nguyên và in ra thay thế

Trong hầu hết thời gian, việc in ra bảng liệt kê dưới dạng số nguyên không phải là điều ta muốn. Thay vào đó ta muốn in ra tên của hằng số liệt kê

1. Getting the name of an enumerator

Có 2 cách thông thường để thực hiện:

Câu lệnh switch có thể chuyển cả giá trị nguyên hoặc giá trị liệt kê

    #include <iostream>
    #include <string_view>

    enum Color
    {
        black,
        red,
        blue,
    };

    constexpr std::string_view getColorname(Color color)
    {
        switch (color)
        {
            case black: return "black";
            case red: return "red";
            case blue: return "blue";
            default: return  "???";
        }
    }

    int main(){
        constexpr Color shirt{blue};
        std::cout << " Your shirt is " << getColorname(shirt) << '\n';

        return 0;

    }

Kết quả in ra:

    Your shirt is blue

Cách thử 2 để giải quyết vấn đề này là sử dụng mảng. Ta sẽ học ở bài sau.

2. Unscoped enumerator input

    Vì Pet là kiểu dữ liệu do chương trình xác định nên ngôn ngữ không biết cách nhập Pet bằng std::cin:

    #include <iostream>

    enum Pet
    {
        cat,   // 0
        dog,   // 1
        pig,   // 2
        whale, // 3
    };

    int main()
    {
        Pet pet { pig };

        std::cin >> pet; // compile error: std::cin doesn't know how to input a Pet

        return 0;
    }

Có 1 cách đơn giản để giải quyết vấn đề này là đọc số nguyên, sử dụng static_cast để chuyển đổi số nguyên thành 1 hằng số liệt kê.

    #include <iostream>
    using namespace std;

    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    constexpr std::string_view getPetName(Pet pet)
    {
        switch (pet)
        {
            case cat: return "cat";
            case dog: return "dog";
            case pig: return "pig";
            case whale: return "whale";
            default: return "???
        }
    }

    int main()
    {
        cout << "Enter a pet (0=cat, 1=dog, 2= pig, 3=whale) ";

        int input{};
        cin >> input;

        if (input < 0 || input > 3)
            cout << "You entered an invalid pet \n";
        else
        {

            Pet pet {static_cast<Pet>(input)};
            cout << "You entered: " << getPetName(pet);
        }
        return 0;
    }

Lưu ý rằng chỉ nên dùng static_cast<Pet>(input) chỉ khi ta biết input trong phạm vi liệt kê. 

3. Getting an enumeration from a string

Thay vì nhập 1 số, sẽ tốt hơn nếu nhập 1 chuỗi biểu diễn hằng số liệt kê ( ví dụ: pig)

    #include <iostream>
    #include <optional> // for std::optional

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

    int main()
    {
        std::cout << "Enter a pet: cat, dog, pig, or whale: ";
        std::string s{};
        std::cin >> s;

        std::optional<Pet> pet { getPetFromString(s) };

        if (!pet)
            std::cout << "You entered an invalid pet\n";
        else
            std::cout << "You entered: " << getPetName(*pet) << '\n';

        return 0;
    }