[In and out parameters](https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/)

Một hàm và người gọi nó giao tiếp với nhau thông qua hai cơ chế: tham số và giá trị trả về. Khi một hàm được gọi, người gọi sẽ cung cấp các đối số mà hàm này nhận được thông qua các tham số của nó. Các đối số này có thể được truyền theo giá trị, tham chiếu hoặc địa chỉ.

1. In parameters

Trong hầu hết trường hợp, Tham số hàm chỉ dùng để nhận giá trị đầu vào từ người gọi. 

Các tham số chỉ được sử dụng để nhận đầu vào từ người gọi đôi khi được gọi tham số vào.

    #include <iostream>

    void print(int x) // x is an in parameter
    {
        std::cout << x << '\n';
    }

    void print(const std::string& s) // s is an in parameter
    {
        std::cout << s << '\n';
    }

    int main()
    {
        print(5);
        std::string s { "Hello, world!" };
        print(s);

        return 0;
    }

x ở đây là tham số vào (in parameter)

2. Out parameters

Tham số hàm chỉ được sử dụng cho mục đích trả lại thông tin cho người gọi được gọi là tham số ra.

    #include <cmath>    // for std::sin() and std::cos()
    #include <iostream>

    // sinOut and cosOut are out parameters
    void getSinCos(double degrees, double& sinOut, double& cosOut)
    {
        // sin() and cos() take radians, not degrees, so we need to convert
        constexpr double pi { 3.14159265358979323846 }; // the value of pi
        double radians = degrees * pi / 180.0;
        sinOut = std::sin(radians);
        cosOut = std::cos(radians);
    }

    int main()
    {
        double sin { 0.0 };
        double cos { 0.0 };

        double degrees{};
        std::cout << "Enter the number of degrees: ";
        std::cin >> degrees;

        // getSinCos will return the sin and cos in variables sin and cos
        getSinCos(degrees, sin, cos);

        std::cout << "The sin is " << sin << '\n';
        std::cout << "The cos is " << cos << '\n';

        return 0;
    }

3. Out parameters have an unnatural syntax

Out - parameter, mặc dù hoạt động tốt nhưng có một số nhược điểm:

    Có thể gây khó hiểu nếu không sử dụng cẩn thận.
    Dễ dẫn đến lỗi nếu không kiểm tra giá trị của out parameter trước khi sử dụng.

Ví dụ:

    #include <iostream>

    int getByValue()
    {
        return 5;
    }

    void getByReference(int& x)
    {
        x = 5;
    }

    int main()
    {
        // return by value
        [[maybe_unused]] int x{ getByValue() }; // can use to initialize object
        std::cout << getByValue() << '\n';      // can use temporary return value in expression

        // return by out parameter
        int y{};                // must first allocate an assignable object
        getByReference(y);      // then pass to function to assign the desired value
        std::cout << y << '\n'; // and only then can we use that value

        return 0;
    }

4. Out-parameters by reference don’t make it obvious the arguments will be modified

Khi chúng ta gán giá trị trả về của hàm cho một đối tượng, rõ ràng giá trị của đối tượng đang được sửa đổi:

x = getByValue(); // obvious that x is being modified

Điều này tốt, bởi vì nó cho ta thấy rõ rành giá trị x được thay đổi

Tuy nhiên, hãy nhìn hàm bên dưới:

    getSinCos(degrees, sin, cos);

Lệnh gọi hàm này không rõ ràng rằng degrees là tham số trong, nhưng sin và cos là tham số ngoài. Nếu người gọi không nhận ra rằng sin và cos sẽ được sửa đổi thì có thể sẽ xảy ra lỗi ngữ nghĩa.

Trong một số trường hợp, việc sử dụng truyền theo địa chỉ thay vì truyền theo tham chiếu có thể giúp làm cho các tham số bên ngoài rõ ràng hơn bằng cách yêu cầu người gọi chuyển địa chỉ của đối tượng làm đối số.

    void foo1(int x);  // pass by value
    void foo2(int& x); // pass by reference
    void foo3(int* x); // pass by address

    int main()
    {
        int i{};

        foo1(i);  // can't modify i
        foo2(i);  // can modify i
        foo3(&i); // can modify i

        int *ptr { &i };
        foo3(ptr); // can modify i

        return 0;
    }

Vì tất cả những lý do này, nên tránh các out-parameters trừ khi không có lựa chọn tốt nào khác.

Best practice:
    Tránh các tham số ngoài (trừ trường hợp hiếm hoi không có lựa chọn nào tốt hơn).

    Ưu tiên chuyển bằng tham chiếu cho các tham số ngoài không tùy chọn.


5. When to pass by non-const reference