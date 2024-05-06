[Return by reference and return by address](https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/)

1. Return by reference

Return by reference trả về một tham chiếu được liên kết với đối tượng được trả về, điều này tránh tạo một bản sao của giá trị trả về. Để trả về theo tham chiếu, chúng ta chỉ cần xác định giá trị trả về của hàm là kiểu tham chiếu:

    std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
    const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)

ví dụ:

    #include <iostream>
    #include <string>

    const std::string& getProgramName() // returns a const reference
    {
        static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

        return s_programName;
    }

    int main()
    {
        std::cout << "This program is named " << getProgramName();

        return 0;
    }

Vì getProgramName() trả về tham chiếu const nên khi dòng return s_programName được thực thi, getProgramName() sẽ trả về tham chiếu const cho s_programName (do đó tránh tạo bản sao). Sau đó, người gọi có thể sử dụng tham chiếu const đó để truy cập giá trị của s_programName

2. The object being returned by reference must exist after the function returns (Đối tượng được trả về bằng tham chiếu phải tồn tại sau khi hàm trả về)

Việc sử dụng trả về theo tham chiếu có một lưu ý chính: Lập trình viên phải đảm bảo đối tượng được tham chiếu tồn tại lâu hơn hàm trả về tham chiếu. Nếu không tham chiếu sẽ bị treo (tham chiếu tới 1 đối tượng đã bị hủy).

ở ví dụ bên trên s_programName có thời lượng tĩnh nên s_programName vẫn sẽ tồn tại đến cuối chương trình.

    #include <iostream>
    #include <string>

    const std::string& getProgramName()
    {
        const std::string programName { "Calculator" }; // now a non-static local variable, destroyed when function ends

        return programName;
    }

    int main()
    {
        std::cout << "This program is named " << getProgramName(); // undefined behavior

        return 0;
    }

Con ở ví dụ này, khi hàm getProgramName() trả về, tham chiếu liên kết với 1 biến cục bộ programName được trả về. Vì programName là biến cục bộ với thời lượng tự động. programName sẽ bị hủy ở cuối hàm. Làm tham chiếu trả về bị treo.

Warning:

    Các đối tượng được trả về bằng tham chiếu phải nằm ngoài phạm vi của hàm trả về tham chiếu, nếu không sẽ dẫn đến tham chiếu treo. Không bao giờ trả về biến cục bộ (không tĩnh) hoặc tạm thời bằng tham chiếu.


3. Lifetime extension doesn’t work across function boundaries

    #include <iostream>

    const int& returnByConstReference()
    {
        return 5; // returns const reference to temporary object
    }

    int main()
    {
        const int& ref { returnByConstReference() };

        std::cout << ref; // undefined behavior

        return 0;
    }

hàm returnByConstReference() trả về 1 số nguyên, nhưng kiểu trả về của hàm là const int&. Nó sẽ tạo ra 1 đối tượng tạm thời chưa giá trị 5 để tham chiếu tạm thời liên kết đến. Khi đối tượng tạm thời(temporary object) vượt qua phạm vi hàm nó sẽ bị hủy và làm tham chiếu bị treo.

Cùng thời điểm đó giá trị được trả về liên kết với 1 tham chiếu const khác ở hàm main. Nhưng đã quá muộn, biến tạm thời đã bị hủy, do đó ref liên kết với 1 tham chiếu treo.

4. Don’t return non-const static local variables by reference

    #include <iostream>
    #include <string>

    const int& getNextId()
    {
        static int s_x{ 0 }; // note: variable is non-const
        ++s_x; // generate the next id
        return s_x; // and return a reference to it
    }

    int main()
    {
        const int& id1 { getNextId() }; // id1 is a reference
        const int& id2 { getNextId() }; // id2 is a reference

        std::cout << id1 << id2 << '\n';

        return 0;
    }

Kết quả in ra là 2 2 chứ không phải kết quả mong muốn là 1 2 vì cả id1 và id2 đều tham chiếu tới cùng 1 đối tượng.

Best practice

Tránh trả về các tham chiếu đến các biến tĩnh cục bộ không phải là hằng.

5. Assigning/initializing a normal variable with a returned reference makes a copy

Nếu một hàm trả về một tham chiếu và tham chiếu đó được dùng để khởi tạo hoặc gán cho một biến không tham chiếu thì giá trị trả về sẽ được sao chép

    #include <iostream>
    #include <string>

    const int& getNextId()
    {
        static int s_x{ 0 };
        ++s_x;
        return s_x;
    }

    int main()
    {
        const int id1 { getNextId() }; // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
        const int id2 { getNextId() }; // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

        std::cout << id1 << id2 << '\n';

        return 0;
    }

hàm getnextId() trả về tham chiếu, nhưng id1, id2 là biến không tham chiếu. Trong trường hợp như này giá trị của tham chiếu trả về được sao chép vào biến bình thường: kết quả in ra 1 2

Lưu ý rằng nếu một chương trình trả về một tham chiếu treo, tham chiếu đó sẽ bị treo trước khi sao chép, điều này sẽ dẫn đến hành vi không xác định:

6. It’s okay to return reference parameters by reference

Nếu một tham số được truyền vào hàm bằng tham chiếu thì việc trả về tham số đó bằng tham chiếu là an toàn. Điều này có ý nghĩa: để truyền một đối số cho một hàm, đối số đó phải tồn tại trong phạm vi của lệnh gọi. Khi hàm được gọi trả về, đối tượng đó vẫn phải tồn tại trong phạm vi của hàm gọi.

    #include <iostream>
    #include <string>

    // Takes two std::string objects, returns the one that comes first alphabetically
    const std::string& firstAlphabetical(const std::string& a, const std::string& b)
    {
        return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
    }

    int main()
    {
        std::string hello { "Hello" };
        std::string world { "World" };

        std::cout << firstAlphabetical(hello, world) << '\n';

        return 0;
    }

Trong hàm trên, người gọi chuyển vào hai đối tượng std::string bằng tham chiếu const và bất kỳ chuỗi nào trong số này xuất hiện trước theo thứ tự bảng chữ cái sẽ được truyền lại bằng tham chiếu const

Nếu chúng ta sử dụng truyền theo giá trị và trả về theo giá trị, chúng ta sẽ tạo tối đa 3 bản sao của std::string (một cho mỗi tham số, một cho giá trị trả về). Bằng cách sử dụng chuyển qua tham chiếu/trả về theo tham chiếu, chúng ta có thể tránh được những bản sao đó.

7. It’s okay to return by const reference an rvalue passed by const reference

Khi một đối số cho tham số tham chiếu const là một giá trị rvalue, bạn vẫn có thể trả về tham số đó bằng tham chiếu const. ??????????

8. The caller can modify values through the reference

Khi một đối số được truyền đến hàm bằng tham chiếu không phải hằng, hàm đó có thể sử dụng tham chiếu đó để sửa đổi giá trị của đối số.

    #include <iostream>

    // takes two integers by non-const reference, and returns the greater by reference
    int& max(int& x, int& y)
    {
        return (x > y) ? x : y;
    }

    int main()
    {
        int a{ 5 };
        int b{ 6 };

        max(a, b) = 7; // sets the greater of a or b to 7

        std::cout << a << b << '\n';

        return 0;
    }

Ở chương trình trên, max(a, b) gọi hàm max với a và b là đối số, tham số x tham chiếu tới a, tham số y tham chiếu tới b. Hàm max sẽ quyết định x hay y là số lớn hơn, trong th là y, Hàm trả về y (vẫn bị ràng buộc với b) cho người gọi. Sau đó, người gọi sẽ gán giá trị 7 cho tham chiếu được trả về này.

8. Return by address

Best practice:

    Ưu tiên trả về theo tham chiếu hơn trả về theo địa chỉ trừ khi khả năng trả về "không có đối tượng" (sử dụng nullptr) rất quan trọng.