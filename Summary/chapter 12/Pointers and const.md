[Pointers and const](https://www.learncpp.com/cpp-tutorial/pointers-and-const/)

    int main()
    {
        int x { 5 };
        int* ptr { &x }; // ptr is a normal (non-const) pointer

        int y { 6 };
        ptr = &y; // we can point at another value

        *ptr = 7; // we can change the value at the address being held

        return 0;
    }

Với con trỏ bình thường, Có thể thay đổi cả địa chỉ con trỏ trỏ tới và giá trị tại địa chỉ được trỏ tới

Tuy nhiên, chuyện gì xảy ra nếu giá trị muốn trỏ đến là const

    int main()
    {
        const int x { 5 }; // x is now const
        int* ptr { &x };   // compile error: cannot convert from const int* to int*

        return 0;
    }

Đoạn mã trên sẽ không được biên dịch - chúng ta không thể đặt con trỏ bình thường để trỏ đến biến const

Biến const là biến có giá trị không thể thay đổi

1. Pointer to const value

Để khai báo một con trỏ tới giá trị hằng, hãy sử dụng từ khóa const trước kiểu dữ liệu của con trỏ:

    int main()
    {
        const int x{ 5 };
        const int* ptr { &x }; // okay: ptr is pointing to a "const int"

        *ptr = 6; // not allowed: we can't change a const value

        return 0;
    }

Trong ví dụ trên, ptr trỏ tới một const int. Vì kiểu dữ liệu được trỏ tới là const nên giá trị được trỏ tới không thể thay đổi.

Tuy nhiên, 1 con trỏ trỏ tới const không phải là const(nó chỉ trỏ tới giá trị const), Ta có thể thay đổi địa chỉ con trỏ trỏ tới bằng cách gán cho nó địa chỉ mới.

    int main()
    {
    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y

    return 0;
    }

Giống tham chiếu tới const, con trỏ tới const có thể trỏ tới giá trị non - const

Một con trỏ tới const coi giá trị được trỏ tới là hằng số, bất kể đối tượng tại địa chỉ đó ban đầu có được xác định là const hay không:

    int main()
    {
        int x{ 5 }; // non-const
        const int* ptr { &x }; // ptr points to a "const int"

        *ptr = 6;  // not allowed: ptr points to a "const int" so we can't change the value through ptr
        x = 6; // allowed: the value is still non-const when accessed through non-const identifier x

        return 0;
    }

2. const pointers

Chúng ta cũng có thể làm cho con trỏ trở thành hằng số. Con trỏ hằng là con trỏ có địa chỉ không thể thay đổi sau khi khởi tạo.

Đẻ khai báo con trỏ const, sử dụng const sau * khi khai báo:

    int x{ 5 };
    int* const ptr { &x }; // const after the asterisk means this is a const pointer

Trong trường hợp trên, ptr là con trỏ hằng tới giá trị int (không phải hằng)

Giá trị của con trỏ const không thể thay đổi thông qua phép gán:

    int x{ 5 };
    int y{ 6 };

    int* const ptr { &x }; // okay: the const pointer is initialized to the address of x
    ptr = &y; // error: once initialized, a const pointer can not be changed.

Vì giá trị trỏ đến không phải là const nên có thể thay đổi giá trị ở địa chỉ trỏ đến thông qua toán tử giải tham chiếu.

    int x{ 5 };
    int* const ptr { &x }; // ptr will always point to x

    *ptr = 6; // okay: the value being pointed to is non-const

3. Const pointer to a const value

Có thể khai báo 1 con trỏ const tới giá trị const bằng cách sử dụng kí tự const ở cả trước và *:

    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value

Con trổ const trỏ tới giá trị const không thể thay đổi địa chỉ cũng không thể thay đổi giá trị tại địa chỉ đó.

4. Pointer and const recap

Tóm tắt, có 4 điều b cần nhớ:

    1. Một con trỏ không phải hằng có thể được gán một địa chỉ khác để thay đổi nội dung nó đang trỏ tới.

    2. Con trỏ hằng luôn trỏ đến cùng một địa chỉ và địa chỉ này không thể thay đổi.

    3. Một con trỏ tới giá trị không phải hằng có thể thay đổi giá trị mà nó đang trỏ tới. Con trỏ bình thường không thể trỏ tới giá trị const

    4. Con trỏ tới giá trị hằng coi giá trị là const khi được truy cập thông qua con trỏ và do đó không thể thay đổi giá trị mà nó đang trỏ tới. Chúng có thể được trỏ tới các giá trị l const hoặc không phải const (nhưng không phải giá trị r, không có địa chỉ).