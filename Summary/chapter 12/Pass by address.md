[Pass by address](https://www.learncpp.com/cpp-tutorial/pass-by-address/)

Ta đã biết có 2 cách khác nhau để truyền đối số cho hàm: truyền bằng giá trị hoặc truyền bằng tham chiếu.


1. Pass by address

C++ cung cấp cách thứ 3 để truyền giá trị vào hàm. Với truyền theo địa chỉ, thay vì cung cấp một đối tượng làm đối số, người gọi sẽ cung cấp địa chỉ của đối tượng (thông qua một con trỏ)

Con trỏ này (giữ địa chỉ của đối tượng) được sao chép vào tham số con trỏ của hàm được gọi. Hàm sau đó có thể giải tham chiếu và truy cập vào đối tượng có địa chỉ được truyền vào

    #include <iostream>
    #include <string>

    void printByValue(std::string val) // The function parameter is a copy of str
    {
        std::cout << val << '\n'; // print the value via the copy
    }

    void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
    {
        std::cout << ref << '\n'; // print the value via the reference
    }

    void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
    {
        std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
    }

    int main()
    {
        std::string str{ "Hello, world!" };

        printByValue(str); // pass str by value, makes a copy of str
        printByReference(str); // pass str by reference, does not make a copy of str
        printByAddress(&str); // pass str by address, does not make a copy of str

        return 0;
    }


2. Pass by address does not make a copy of the object being pointed to

    std::string str{ "Hello, world!" };
    printByAddress(&str); // use address-of operator (&) to get pointer holding address of str

Như đã đề cập, sao chép std::string khá "đắt", đó là thứ ta muốn tránh. Khi truyền std::string bằng địa chỉ, ta không sao chép đối tượng std::string, ta chỉ sao chép con trỏ(trỏ đến địa chỉ của đối tượng). BVì địa chỉ thường chỉ có 4 hoặc 8 byte nên con trỏ chỉ có 4 hoặc 8 byte nên việc sao chép con trỏ luôn nhanh.

3. Pass by address allows the function to modify the argument’s value

Khi truyền đối tượng qua địa chỉ, hàm nhận địa chỉ của đối tượng được truyền vào, nếu tham số hàm là một con trỏ trỏ tới giá trị non-const, hàm có thể sửa đổi đối số thông qua tham số con trỏ:

    #include <iostream>

    void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
    {
        *ptr = 6; // change the value to 6
    }

    int main()
    {
        int x{ 5 };

        std::cout << "x = " << x << '\n';

        changeValue(&x); // we're passing the address of x to the function

        std::cout << "x = " << x << '\n';

        return 0;
    }

4. Null checking

    #include <iostream>
    #include <cassert>

    void print(const int* ptr) // now a pointer to a const int
    {
        assert(ptr); // fail the program in debug mode if a null pointer is passed (since this should never happen)

        // (optionally) handle this as an error case in production mode so we don't crash if it does happen
        if (!ptr)
            return;

        std::cout << *ptr << '\n';
    }

    int main()
    {
        int x{ 5 };

        print(&x);
        print(nullptr);

        return 0;
    }

5. Prefer pass by (const) reference

Truyền qua tham chiếu const có một vài ưu điểm khác so với truyền theo địa chỉ.
    1. Đầu tiên, vì một đối tượng được truyền theo địa chỉ phải có một địa chỉ, nên chỉ các giá trị có thể được truyền theo địa chỉ (vì các giá trị không có địa chỉ). Truyền qua tham chiếu const linh hoạt hơn, vì nó có thể chấp nhận giá trị và giá trị:

    2. Thứ hai, cú pháp truyền theo tham chiếu là tự nhiên, vì chúng ta chỉ có thể truyền theo nghĩa đen hoặc đối tượng. Với việc chuyển qua địa chỉ, mã của chúng tôi sẽ có rất nhiều ký hiệu và (&) và dấu hoa thị (*).


Best practice
    Ưu tiên chuyển qua tham chiếu hơn chuyển theo địa chỉ trừ khi bạn có lý do cụ thể để sử dụng chuyển theo địa chỉ.