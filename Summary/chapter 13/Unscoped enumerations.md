[Unscoped enumerations](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)

C++ chứa nhiều kiểu dữ liệu cơ bản và kết hợp hữu dụng Nhưng những loại này không phải lúc nào cũng đủ cho những việc chúng ta muốn làm.

Ví dụ:

Ví dụ: giả sử bạn đang viết một chương trình cần theo dõi xem quả táo có màu đỏ, vàng hay xanh lục hay áo sơ mi có màu gì (từ danh sách màu đặt trước). Nếu chỉ có những loại cơ bản thì bạn có thể làm điều này như thế nào?

1. Enumerations

Kiểu liệt kê (còn được gọi là kiểu liệt kê hoặc kiểu enum) là kiểu dữ liệu phức hợp có giá trị được giới hạn trong một tập hợp các hằng số ký hiệu được đặt tên (được gọi là Liệt kê).

C++ hỗ trợ hai loại liệt kê: liệt kê không có phạm vi (chúng ta sẽ đề cập đến bây giờ) và liệt kê có phạm vi (chúng ta sẽ đề cập ở phần sau của chương này).

Vì enum là program - defined types mỗi bảng liệt kê cần phải được xác định đầy đủ trước khi chúng ta có thể sử dụng nó (một khai báo chuyển tiếp là không đủ).

2. Unscoped enumerations

Unscoped enumerations được định nghĩa thông qua từ khóa enum

Ví dụ:

    // Define a new unscoped enumeration named Color
    enum Color
    {
        // Here are the enumerators
        // These symbolic constants define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        red,
        green,
        blue, // trailing comma optional but recommended
    }; // the enum definition must end with a semicolon

    int main()
    {
        // Define a few variables of enumerated type Color
        Color apple { red };   // my apple is red
        Color shirt { green }; // my shirt is green
        Color cup { blue };    // my cup is blue

        Color socks { white }; // error: white is not an enumerator of Color
        Color hat { 2 };       // error: 2 is not an enumerator of Color

        return 0;
    }

Chúng tôi bắt đầu ví dụ của mình bằng cách sử dụng từ khóa enum để báo cho trình biên dịch biết rằng chúng tôi đang xác định một bảng liệt kê không có phạm vi mà chúng tôi đặt tên là Màu.

Bên trong main(), chúng ta khởi tạo ba biến kiểu Color: táo được khởi tạo với màu đỏ, sơ mi được khởi tạo với màu xanh lục và cốc được khởi tạo với màu xanh lam. Bộ nhớ được phân bổ cho từng đối tượng này

3. Naming enumerations and enumerators

Best practice

    Đặt tên cho kiểu liệt kê của bạn bắt đầu bằng chữ in hoa. Đặt tên cho thành phần liệt kê của bạn bắt đầu bằng một chữ cái viết thường.

Các bảng liệt kê không nhất thiết phải được đặt tên, nhưng nên tránh các bảng liệt kê không có tên trong C++ hiện đại.

4. Enumerated types are distinct types

Mỗi kiểu liệt kê bạn tạo được coi là một kiểu riêng biệt

Bởi vì các kiểu liệt kê là khác nhau, nên các thành phần liệt kê được xác định là một phần của một kiểu liệt kê không thể được sử dụng với các đối tượng thuộc kiểu liệt kê khác:

ví dụ:

    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    enum Color
    {
        black,
        red,
        blue,
    };

    int main()
    {
        Pet myPet { black }; // compile error: black is not an enumerator of Pet
        Color shirt { pig }; // compile error: pig is not an enumerator of Color

        return 0;
    }

5. Putting enumerations to use

Bởi vì các thành phần liệt kê mang tính mô tả nên chúng rất hữu ích trong việc nâng cao khả năng đọc và tài liệu mã

Đôi khi các hàm sẽ trả về mã trạng thái cho người gọi để cho biết hàm đó được thực thi thành công hay gặp lỗi

Theo truyền thống, các số âm nhỏ được sử dụng để biểu thị các mã lỗi khác nhau có thể xảy ra. Ví dụ:

    int readFileContents()
    {
        if (!openFile())
            return -1;
        if (!readFile())
            return -2;
        if (!parseFile())
            return -3;

        return 0; // success
    }

Tuy nhiên, việc sử dụng những con số như thế này không mang tính mô tả nhiều. Một phương pháp tốt hơn là sử dụng kiểu liệt kê:

    enum FileReadResult
    {
        readResultSuccess,
        readResultErrorFileOpen,
        readResultErrorFileRead,
        readResultErrorFileParse,
    };

    FileReadResult readFileContents()
    {
        if (!openFile())
            return readResultErrorFileOpen;
        if (!readFile())
            return readResultErrorFileRead;
        if (!parseFile())
            return readResultErrorFileParse;

        return readResultSuccess;
    }

Sau đó, người gọi có thể kiểm tra giá trị trả về của hàm dựa vào thành phần liệt kê thích hợp, điều này dễ hiểu hơn là kiểm tra kết quả trả về cho một giá trị số nguyên cụ thể.

Các loại liệt kê cũng có thể được sử dụng hiệu quả trong trò chơi, để xác định các loại vật phẩm, quái vật hoặc địa hình khác nhau.

    enum ItemType
    {
        sword,
        torch,
        potion,
    };

    int main()
    {
        ItemType holding{ torch };

        return 0;
    }

Các kiểu liệt kê cũng có thể tạo ra các tham số hàm hữu ích khi người dùng cần đưa ra lựa chọn giữa hai hoặc nhiều tùy chọn:

    enum SortOrder
    {
        alphabetical,
        alphabeticalReverse,
        numerical,
    };

    void sortData(SortOrder order)
    {
        switch (order)
        {
            case alphabetical:
                // sort data in forwards alphabetical order
                break;
            case alphabeticalReverse:
                // sort data in backwards alphabetical order
                break;
            case numerical:
                // sort data numerically
                break;
        }
    }

6. The scope of unscoped enumerations

Unscoped enumerations được đặt tên như vậy bởi vì chúng đặt tên thành phần liệt kê của chúng vào cùng phạm vi với chính định nghĩa liệt kê (ngược lại với việc tạo một vùng phạm vi mới giống như một không gian tên).

Ví dụ:

    enum Color // this enum is defined in the global namespace
    {
        red, // so red is put into the global namespace
        green,
        blue,
    };

    int main()
    {
        Color apple { red }; // my apple is red

        return 0;
    }

enum Color được xác định trong phạm vi toàn cục. Do đó, tất cả các tên liệt kê (đỏ, lục và lam) cũng thuộc phạm vi toàn cục. Điều này làm ô nhiễm phạm vi toàn cục và làm tăng đáng kể khả năng xảy ra xung đột khi đặt tên.

Một hậu quả của việc này là tên thành phần liệt kê không thể được sử dụng trong nhiều bảng liệt kê trong cùng một phạm vi

    enum Color
    {
        red,
        green,
        blue, // blue is put into the global namespace
    };

    enum Feeling
    {
        happy,
        tired,
        blue, // error: naming collision with the above blue
    };

    int main()
    {
        Color apple { red }; // my apple is red
        Feeling me { happy }; // I'm happy right now (even though my program doesn't compile)

        return 0;
    }

Trong ví dụ trên, cả hai kiểu liệt kê không có phạm vi (Color và Feeling) đều đặt các thành phần liệt kê có cùng tên màu xanh lam vào phạm vi toàn cục. Điều này dẫn đến xung đột đặt tên và lỗi biên dịch sau đó.

7. Avoiding enumerator naming collisions

Đây là 1 vài cách phổ biến để tránh xung đột tên cho unscoped enumerator(các thành phần liệt kê không phạm vi)

Một lựa chọn là thêm tên của chính bảng liệt kê vào tiền tố:

    enum Color
    {
        color_red,
        color_blue,
        color_green,
    };

    enum Feeling
    {
        feeling_happy,
        feeling_tired,
        feeling_blue, // no longer has a naming collision with color_blue
    };

    int main()
    {
        Color paint { color_blue };
        Feeling me { feeling_blue };

        return 0;
    }

Điều này vẫn gây ô nhiễm không gian tên nhưng làm giảm nguy cơ xung đột khi đặt tên bằng cách làm cho tên dài hơn và độc đáo hơn.

Một lựa chọn tốt hơn là đặt kiểu liệt kê bên trong thứ gì đó cung cấp một vùng phạm vi riêng biệt, chẳng hạn như không gian tên:

    namespace Color
    {
        // The names Color, red, blue, and green are defined inside namespace Color
        enum Color
        {
            red,
            green,
            blue,
        };
    }

    namespace Feeling
    {
        enum Feeling
        {
            happy,
            tired,
            blue, // Feeling::blue doesn't collide with Color::blue
        };
    }

    int main()
    {
        Color::Color paint{ Color::blue };
        Feeling::Feeling me{ Feeling::blue };

        return 0;
    }

Best practice:

    Ưu tiên đặt các bảng liệt kê của bạn bên trong một vùng phạm vi được đặt tên (chẳng hạn như không gian tên hoặc lớp) để tránh làm ô nhiễm không gian tên chung.

8. Comparing against enumerators

Chúng ta có thể sử dụng các toán tử đẳng thức (toán tử== và toán tử!=) để kiểm tra xem một bảng liệt kê có giá trị của thành phần liệt kê cụ thể hay không.

    #include <iostream>

    enum Color
    {
        red,
        green,
        blue,
    };

    int main()
    {
        Color shirt{ blue };

        if (shirt == blue) // if the shirt is blue
            std::cout << "Your shirt is blue!";
        else
            std::cout << "Your shirt is not blue!";

        return 0;
    }