[Null pointers](https://www.learncpp.com/cpp-tutorial/null-pointers/)

1. Null pointers

Bên cạnh địa chỉ bộ nhớ, có thêm 1 giá trị nữa con trỏ có thể chứa: giá trị null. Giá trị null là giá trị đặc biệt có nghĩa là thứ gì đó không có giá trị. Khi con trỏ giữ giá trị null có nghĩa là con trỏ không trỏ vào bất cứ thứ gì. Những con trỏ như vậy gọi là con trỏ rỗng.

ví dụ:
    int main()

    {
    int* ptr {}; // ptr is now a null pointer, and is not holding an address

    return 0;
    }


Best practice:

    Nếu bạn không gán địa chỉ của một đối tượng hợp lệ cho con trỏ, hãy khởi tạo giá trị ban đầu của nó thành con trỏ null

Có thể dùng lệnh gán để thay đổi đối tượng con trỏ đang trỏ tới, ban đầu con trỏ được set thành null sau đó có thể chuyển để  trỏ sáng 1 đối tượng hợp lệ.

Ví dụ:
    #include <iostream>

    int main()
    {
    int* ptr {}; // ptr is a null pointer, and is not holding an address

    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    return 0;
    }

2. The nullptr keyword (explicity: rõ ràng)

Từ khóa nullptr đại diện cho con trỏ rỗng. Có thể sử dụng nullptr để khởi tạo 1 cách rõ ràng hoặc gán cho con trỏ 1 giá trị rỗng. 

    int main()
    {
        int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

        int value { 5 };
        int* ptr2 { &value }; // ptr2 is a valid pointer
        ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

        someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

        return 0;
    }

Best practice:

    Sử dụng nullptr khi bạn cần một con trỏ null để khởi tạo, gán hoặc truyền một con trỏ null tới một hàm.

3. Dereferencing a null pointer results in undefined behavior

Giống như việc hủy tham chiếu một con trỏ lơ lửng  dẫn đến hành vi không xác định, việc hủy tham chiếu một con trỏ null cũng dẫn đến hành vi không xác định. Trong hầu hết các trường hợp, nó sẽ gây lỗi.

4. Checking for null pointers

Giông với việc sử dụng điều kiện để kiểm tra giá trị Boolean là đúng hay sai. Có thể sử dụng điều kiện để kiểm tra con trỏ có giá trị null hay không.

    #include <iostream>

    int main()
    {
        int x { 5 };
        int* ptr { &x };

        if (ptr == nullptr) // explicit test for equivalence
            std::cout << "ptr is null\n";
        else
            std::cout << "ptr is non-null\n";

        int* nullPtr {};
        std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n"); // explicit test for equivalence

        return 0;
    }

con trỏ cũng sẽ ngầm chuyển đổi thành giá trị Boolean: con trỏ null chuyển đổi thành giá trị Boolean false và con trỏ không null chuyển đổi thành giá trị Boolean true. Điều này cho phép chúng tôi bỏ qua việc kiểm tra rõ ràng nullptr và chỉ sử dụng chuyển đổi ngầm định thành Boolean để kiểm tra xem một con trỏ có phải là con trỏ null hay không.

5. Use nullptr to avoid dangling pointers

Giải tham chiếu của dangling pointer hay null poiter đều dẫn đến hành vi không xác định

Nhưng null pointer có thể kiểm tra bằng cách sử dụng điều kiện trước khi giải tham chiếu

Dangling pointer thì không có cách nào để phát hiện. Ta cần phải tránh bất kì dangling pointer trong trương trình đầu tiên. Có thể tránh được bằng cách đặt bất kì con trỏ nào không trỏ tới 1 đối tượng xác định thành con trỏ null

Best practice:
    Một con trỏ phải giữ địa chỉ của một đối tượng hợp lệ hoặc được đặt thành nullptr. Bằng cách đó, chúng ta chỉ cần kiểm tra con trỏ xem có null không và có thể giả sử mọi con trỏ không null đều hợp lệ.

Khi đối tượng mà con trỏ đang trỏ đến bị hủy, con trỏ sẽ bị treo và không tự động chuyển thành con trỏ null. Người lập trình phải chịu tránh nhiệm chuyển những con trỏ tới đối tượng bị hủy thành nullptr

6. Legacy null pointer literals: 0 and NULL

Có thể sử dụng 0 và null để khai báo con trỏ rỗng:

    double* ptr { NULL } // ptr is a null pointer

    ptr2 = NULL; // ptr2 is now a null pointer

hoặc:

    float* ptr { 0 };  // ptr is now a null pointer (for example only, don't do this)
    ptr2 = 0; // ptr2 is now a null pointer (for example only, don't do this)

Cả 0 và null đều nên tránh , thay vào đó ta sử dụng nullptr.

7. Favor references over pointers whenever possible (Ưu tiên sử dụng tham chiếu hơn con trỏ bất cứ khi nào có thể)

Con trỏ và tham chiếu đều cho chúng ta khả năng truy cập gián tiếp vào một số đối tượng khác

Con trỏ có các khả năng thay đổi những gì chúng đang trỏ tới và được trỏ về giá trị rỗng.

Vì các tham chiếu không thể liên kết với null nên chúng ta không phải lo lắng về các tham chiếu null. Và bởi vì các tham chiếu phải được liên kết với một đối tượng hợp lệ khi tạo và sau đó không thể được thay đổi, nên các tham chiếu treo sẽ khó tạo hơn.

Best practice:

    Ưu tiên các tham chiếu hơn con trỏ trừ khi cần có các khả năng bổ sung do con trỏ cung cấp.