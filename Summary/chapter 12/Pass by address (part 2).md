[Pass by address (part 2)](https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/#google_vignette)

1. Pass by address for “optional” arguments

Một trong những cách sử dụng phổ biến hơn của việc truyền địa chỉ là cho phép một hàm chấp nhận đối số "tùy chọn". Điều này dễ minh họa hơn bằng ví dụ:


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

Chương trình trên, hàm printIDNumber() có 1 tham số được truyền qua địa chỉ và mặc định với giá trị null. 

Gọi hàm 2 lần, lần đầu tiên gọi hàm không có đối số. Lần thứ 2 tham số nhận địa chỉ của userid.

Tuy nhiên trong nhiều trường hợp , sử dụng hàm xếp chồng là giải pháp tôt hơn cho ra cùng 1 kết quả.

    #include <iostream>

    void printIDNumber()
    {
        std::cout << "Your ID is not known\n";
    }

    void printIDNumber(int id)
    {
        std::cout << "Your ID is " << id << "\n";
    }

    int main()
    {
        printIDNumber(); // we don't know the user's ID yet

        int userid { 34 };
        printIDNumber(userid); // we know the user is 34

        printIDNumber(62); // now also works with rvalue arguments

        return 0;
    }

2. Changing what a pointer parameter points at

Khi chúng ta truyền một địa chỉ cho một hàm, địa chỉ đó sẽ được sao chép từ đối số sang tham số con trỏ

    #include <iostream>

    // [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
    void nullify([[maybe_unused]] int* ptr2)
    {
        ptr2 = nullptr; // Make the function parameter a null pointer
    }

    int main()
    {
        int x{ 5 };
        int* ptr{ &x }; // ptr points to x

        std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

        nullify(ptr);

        std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
        return 0;
    }

Thay đổi địa chỉ được giữ bởi tham số con trỏ không ảnh hưởng đến địa chỉ được giữ bởi đối số (ptr vẫn trỏ vào x)

Khi hàm thay đổi địa chỉ ptr2 trỏ vào, nó chỉ ảnh hưởng đến bản copy địa chỉ được truyền vào ptr2. 

3. Pass by address… by reference?

Đây là cách để thay đổi địa chỉ con trỏ trỏ tới thông qua hàm.

Giống như chúng ta có thể truyền một biến thông thường bằng tham chiếu, chúng ta cũng có thể truyền con trỏ bằng tham chiếu. Đây là chương trình tương tự như trên với ptr2 được thay đổi để tham chiếu đến một địa chỉ:

    #include <iostream>

    void nullify(int*& refptr) // refptr is now a reference to a pointer
    {
        refptr = nullptr; // Make the function parameter a null pointer
    }

    int main()
    {
        int x{ 5 };
        int* ptr{ &x }; // ptr points to x

        std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

        nullify(ptr);

        std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
        return 0;
    }

    Vì refptr bây giờ là một tham chiếu đến một con trỏ, nên khi ptr được truyền dưới dạng đối số, refptr sẽ bị ràng buộc với ptr. Điều này có nghĩa là mọi thay đổi đối với refptr đều được thực hiện đối với ptr

4. Why using 0 or NULL is no longer preferred (optional)

Chữ số 0 có thể được hiểu là chữ nguyên hoặc là chữ con trỏ null. Trong một số trường hợp nhất định, có thể mơ hồ chúng ta dự định chọn cái nào. Và một số trường hợp trong đó, trình biên dịch có thể hiểu nhầm 

Định nghĩa về macro NULL không được xác định theo tiêu chuẩn ngôn ngữ. Nó có thể được định nghĩa là 0, 0L, ((void*)0) hoặc một giá trị nào đó hoàn toàn khác.

5. std::nullptr_t (optional)

void printValue(int value);
void printValue(const int* pointer);

Nếu nullptr được coi là int, trình biên dịch sẽ không thể xác định hàm nào được gọi khi bạn truyền nullptr cho printValue. Do đó, việc sử dụng nullptr cần một kiểu dữ liệu riêng biệt để nó có thể được phân biệt rõ ràng với các giá trị số nguyên trong quá tải hàm.

C++ giới thiệu kiểu dữ liệu std::nullptr_t để đại diện cho giá trị nullptr(nó được định nghĩa trong thư viện <cstddef>). std::nullptr_t ó thể giữ 1 giá trị: nullptr 

Nếu chúng ta muốn viết một hàm chỉ chấp nhận đối số bằng chữ nullptr, chúng ta có thể đặt tham số này là std::nullptr_t

    #include <iostream>
    #include <cstddef> // for std::nullptr_t

    void print(std::nullptr_t)
    {
        std::cout << "in print(std::nullptr_t)\n";
    }

    void print(int*)
    {
        std::cout << "in print(int*)\n";
    }

    int main()
    {
        print(nullptr); // calls print(std::nullptr_t)

        int x { 5 };
        int* ptr { &x };

        print(ptr); // calls print(int*)

        ptr = nullptr;
        print(ptr); // calls print(int*) (since ptr has type int*)

        return 0;
    }

Chỉ khi ta truyền đối số nullptr mới gọi đúng hàm:

    void print(std::nullptr_t)
    {
        std::cout << "in print(std::nullptr_t)\n";
    }

5. There is only pass by value

chúng ta có thể kết luận rằng C++ thực sự "pass everything by value" Các thuộc tính của truyền theo địa chỉ (và tham chiếu) chỉ xuất phát từ thực tế là chúng ta có thể giải tham chiếu địa chỉ đã truyền để thay đổi đối số, điều mà chúng ta không thể thực hiện với tham số giá trị bình thường!